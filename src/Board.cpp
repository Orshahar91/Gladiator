#include "Board.h"
#include <experimental/vector>



Board::Board(): m_life(LIFE), m_score(SCORE), m_Num_Of_Diamonds(0), m_level(0)
{
	
}

Board::~Board()
{

}

void Board::Clear_Board()
{
	m_monsters.clear();
	m_statics.clear();
}

void Board::ReleaseDigger()
{
	m_Digger.release();
}

void Board::LoadBoard(Asset_Manager &manage, std::fstream &file, const unsigned &rows, const unsigned &cols,const int &stones,const float &time)
{

	m_Num_Of_Diamonds = 0;
	sf::Vector2f Size;
	Size.x = SCREEN_WIDTH / cols;
	Size.y = (SCREEN_HEIGHT - DATABAR_HEIGHT) / rows;
	m_Stones = m_OriginalStones = stones;
	m_Timer = m_OriginalTime = time;
	m_LevelCompleted = false;
	m_DataBar.LoadBar(manage);
	m_DataBar.SetTimer(m_Timer);
	m_board.setTexture(&manage.GetTexture(O_ARENA));
	m_timeAU.setBuffer(manage.GetSound(O_TIME));
	m_youloseAU.setBuffer(manage.GetSound(O_YOULOSE));

	file.get();		
	for (unsigned i = 0; i < rows; i++)
	{
		string line;
		getline(file, line);	// read  line
		for (unsigned j = 0; j < cols; j++)
		{
			Char_t c = (Char_t)line[j];	
			const sf::Vector2f currPos = sf::Vector2f((float)j * Size.x  , (float)i * Size.y + DATABAR_HEIGHT);	
			switch (c)
			{
			case C_DIGGER:

				if (!m_Digger)
				{
					m_life = LIFE;
					m_score = SCORE;
				}

				else
					m_score = m_Digger->GetScore();

					m_Digger = (std::make_unique<Digger>(m_score,m_life,manage.GetTexture(O_MOVEMENT), currPos, sf::Vector2f(Size.x - 15 , Size.y - 15)));

					m_Digger->SetStone(m_Stones);

					if (time != -1) // This level has a time limit (use for the gift's randomness)
						m_Digger->SetLimitedTime(true);

					m_Digger->setStartingPosition(currPos);	// set starting position
					m_Digger->reset();						// reset the digger
					
				break;
			case C_WALL:
				m_statics.emplace_back(std::make_unique<Wall>(manage.GetTexture(O_WALL), currPos, Size));	
				break;
			case C_MONSTER:
				addMonster(manage.GetTexture(O_SMARTMON),manage.GetTexture(O_REGMON),  currPos, sf::Vector2f(Size.x - 15, Size.y - 15));
				break;
			case C_DIAMOND:
				m_statics.emplace_back(std::make_unique<Diamond>(manage.GetTexture(O_DIAMOND), currPos, Size));
				m_Num_Of_Diamonds++;
				break;
			case C_STONE:
				m_statics.emplace_back(std::make_unique<Stone>(manage.GetTexture(O_STONE), currPos, Size));
				break;
			case C_GIFT:
				m_statics.emplace_back(std::make_unique<Gift>(manage.GetTexture(O_GIFT), currPos, Size));
				break;
			case C_STONE_AND_GIFT:	// make gift and stoone objects in the same position
				
				m_statics.emplace_back(std::make_unique<Gift>(manage.GetTexture(O_GIFT), sf::Vector2f(currPos.x + 2, currPos.y + 2), sf::Vector2f(Size.x - (Size.x / 3), Size.y - (Size.y / 3))));
				m_statics.emplace_back(std::make_unique<Stone>(manage.GetTexture(O_STONE), currPos, Size));
				break;
			default:
				break;
			}
		}
	}
	m_Digger->SetDiamonds(m_Num_Of_Diamonds);
}

void Board::Create()
{
	m_board.setSize(BoardSize);
	m_board.setPosition(BoardPos);
}

void Board::draw(sf::RenderWindow & window)
{
	window.draw(m_board);	// draw the board Rectangle Shape 
	for (auto& Statics : m_statics)			// draw statics on the board
		Statics->draw(window);
	m_Digger->draw(window);	// draw the digger on the board
	for (auto& Monsters : m_monsters)
		Monsters->draw(window);// draw monsters on the board
}

void Board::DrawDataBar(sf::RenderWindow&window)
{
	 m_DataBar.Draw(window);
}

void Board::IncreaseLevel()
{
	m_level++;
	m_DataBar.SetLevel(m_level);
}



void Board::move_moveables()
{
	float dt = m_GameClock.restart().asSeconds();
	m_Digger->move(dt, { 0,0 }, m_board);
	handleCollisions(*m_Digger);

	for (auto& Monsters : m_monsters)
	{
		Monsters->move(dt, { m_Digger->GetPosition() }, m_board);
		handleCollisions(*Monsters);
	}
	std::experimental::erase_if(m_statics, [](auto& Static)
		{
			return Static->isDisposed();
			
		});

}

void Board::addMonster(const sf::Texture& smart, const sf::Texture& dumb, const sf::Vector2f& pos, const sf::Vector2f& size)
{
	unsigned randMon = rand() % 100;	// generate a random number
	if (randMon % 2 == 0)	// if even number - create smart monster
		m_monsters.push_back(std::make_unique<SmartMonster>(smart, pos, size));
	else					// if odd number - create dumb monster
		m_monsters.push_back(std::make_unique<RegularMonster>(dumb, pos, size));
}

void Board::handleCollisions(Objects& Object)
{
	for (auto& Static : m_statics)
	{
		if (Object.checkCollision(Static->getGlobalBounds()))
		{
			Object.HandleCollision(*Static);
		}
	}

	

	for (auto& monster : m_monsters)
	{
		if (Object.checkCollision(monster->getGlobalBounds()))
		{
			Object.HandleCollision(*monster);
		}
	}

	if (Object.checkCollision(m_Digger->getGlobalBounds()))
		Object.HandleCollision(*m_Digger);



}

void Board::UpdateDataBar()
{
	m_life = m_Digger->GetLife();
	m_score = m_Digger->GetScore();
	m_Stones = m_Digger->Getstone();
	m_Time = m_Digger->GetTime();

	m_DataBar.AddTime(m_Time);
	m_Digger->InitTime(); // Initialize the added time received from a gift
	m_DataBar.SetLife(m_life);
	m_DataBar.SetStones(m_Stones);
	m_DataBar.SetScore(m_score);
}

void Board::ResetLevel()
{
	m_level = 0;
}

bool Board::GameOver()
{
	if (m_Digger->isDisposed())
	{
		return  true;
	}
	return false;
}

bool Board::LevelCompleted() const
{
	return m_LevelCompleted;
}

void Board::GameStats()
{

	m_Num_Of_Diamonds = m_Digger->GetDiamonds();
	if (m_Num_Of_Diamonds == 0)
	{
		m_LevelCompleted = true;
		m_Digger->AddScore(SCORE_LEVEL);
	}

	else if (m_DataBar.GetTimer() <=  0 && m_DataBar.GetTimer() > -1)
	{
		m_timeAU.play();
		Restart();
	}

	else if (m_Digger->Getstone() < 0)
	{
		m_youloseAU.play();
		Restart();
	}
}

void Board::Restart()
{
	m_Digger->reset();
	m_Digger->DecreaseLife();

	for (auto& monster : m_monsters)
		monster->reset();

	m_Digger->SetStone(m_OriginalStones);
	m_DataBar.SetTimer(m_OriginalTime);

}

void Board::SetInfinity(const bool & is_infinite)
{
	m_DataBar.SetInfiniteTime(is_infinite);
}