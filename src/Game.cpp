#include "Game.h"




Game::Game() : GameCompleted(false)
{
}

Game::~Game()
{
}

void Game::Run()
{

	bool start = false;

	bool gameover = false;

	bool lvlcomplete = false;

	LoadTextures();

	sf::Sound musicAU;
	sf::Sound victoryAU;
	sf::Sound beginAU;
	sf::Sound gameoverAU;
	sf::Sound winnerAU;
	sf::Sound you_winAU;

	m_Window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Digger", sf::Style::Fullscreen );

	Sounds(musicAU, O_MUSIC, MUSIC_VOL, LOOP_ON);
	Sounds(victoryAU, O_VICTORIOUS, MUSIC_VOL, LOOP_ON);
	Sounds(beginAU, O_BEGIN, FULL_VOL, LOOP_OFF);
	Sounds(gameoverAU, O_GAMEOVER, FULL_VOL, LOOP_OFF);
	Sounds(winnerAU, O_WINNER, FULL_VOL, LOOP_OFF);
	Sounds(you_winAU, O_YOUWIN, FULL_VOL, LOOP_OFF);

	sf::Text GameOverTXT;
	sf::Text GameCompletedTXT;

	GameOverTXT = CreateText(MsgSize, m_manage.GetFont(O_FONT), TXT_MSG_POS , " { G@ME ~# OVER } ");
	GameCompletedTXT = CreateText(MsgSize, m_manage.GetFont(O_FONT), TXT_MSG_POS, "{ ~ {WINNER} # }");



	m_menu.Draw(m_Window, start, m_manage);

	

	musicAU.play();
	beginAU.play();
	

	m_myfile.open("Board.txt");

	


	while ((start) && (!gameover))
	{
		LoadLevel();
		
		m_Board.IncreaseLevel();
		lvlcomplete = false;
		while (m_Window.isOpen() && (!gameover) && (!lvlcomplete) )
		{
			HandleEvents();
			m_Board.UpdateDataBar();
			Draw();
			m_Board.move_moveables();
			m_Board.GameStats();

			if (m_Board.GameOver())
			{
				
				gameover = true;
				
			}

			if (m_Board.LevelCompleted())
			{
				lvlcomplete = true;

				you_winAU.play();
			}
			
		}


		if (gameover || GameCompleted)
		{
			if (gameover)
			{
				m_Clock.restart().asSeconds();

				while (m_Clock.getElapsedTime().asSeconds() < 1) // just to wait for the other sound to finish if there were any

				gameoverAU.play();

				DisplayMsg(GameOverTXT);

			}

			if (GameCompleted)
			{
				musicAU.stop();
				you_winAU.stop();
				victoryAU.play();
				winnerAU.play();
				DisplayMsg(GameCompletedTXT);	
				victoryAU.stop();
			}

			start = false;
			m_myfile.seekg(0, std::ios::beg);
			m_Board.Clear_Board();
			m_menu.Draw(m_Window, start, m_manage);
			musicAU.play();
			if (!start)
			{
				m_Window.close();
			}

			else
			{
				m_Board.ResetLevel();
				m_Board.ReleaseDigger();
				gameover = false;
				start = true;
				GameCompleted = false;
				beginAU.play();
			}
				
		}
		
	}


}

void Game::Sounds(sf::Sound &Sound, const int & name, const int &Volume, const bool & loop)
{
	Sound.setBuffer(m_manage.GetSound(name));
	Sound.setVolume(Volume);
	Sound.setLoop(loop);
}

void Game::Draw()
{
	m_Window.clear();
	m_Board.draw(m_Window);
	m_Board.DrawDataBar(m_Window);
	m_Window.display();
}

void Game::HandleEvents()
{
	sf::Event event;
	if (m_Window.pollEvent(event))
	{
		if(event.type == sf::Event::Closed)
		{
			m_Window.close();
		}
	}
}

void Game::DisplayMsg(const sf::Text & txt)
{
	m_Clock.restart().asSeconds();

	while (m_Window.isOpen())
	{
		sf::Event event;
		if (m_Window.waitEvent(event))
		{
			m_Window.draw(txt);
			m_Window.display();

			if ((event.type == sf::Event::KeyPressed) && (m_Clock.getElapsedTime().asSeconds() >= 2))
				break;
		}
	}
}

void Game::LoadLevel()
{
	if (m_myfile.eof())	// if we got to the end of file and there are no more levels left
	{
		GameCompleted = true;
		return;
	}
	m_Board.Clear_Board();	// Clears the board from every object
	m_Board.SetInfinity(false); // Initialize boolean value for the display of the infinity icon

	int rows, cols, stones, timer;
	m_myfile >> rows >> cols >> stones >> timer;	// read from file: rows, cols, stones, level time

	if (timer == -1)
		m_Board.SetInfinity(true);
	

	m_Board.Create();
	m_Board.LoadBoard(m_manage, m_myfile, rows, cols, stones, timer);

}

void Game::LoadTextures()
{


	m_manage.LoadTexture(O_WALL, WALL_PNG_FILEPATH);
	m_manage.LoadTexture(O_GIFT, GIFT_PNG_FILEPATH);
	m_manage.LoadTexture(O_STONE, STONE_PNG_FILEPATH);
	m_manage.LoadTexture(O_DIAMOND, DIAMOND_PNG_FILEPATH);
	m_manage.LoadTexture(O_MENU, MENU_PNG_FILEPATH);
	m_manage.LoadFont(O_FONT, FONT_TTF_FILEPATH);
	m_manage.LoadTexture(O_ARENA, ARENA_PNG_FILEPATH);
	m_manage.LoadSound(O_START, START_OGG_FILEPATH);
	m_manage.LoadSound(O_QUIT, QUIT_OGG_FILEPATH);
	m_manage.LoadSound(O_MUSIC, MUSIC_OGG_FILEPATH);
	m_manage.LoadTexture(O_START_BUT, START_PNG_FILEPATH);
	m_manage.LoadTexture(O_EXIT_BUT, EXIT_PNG_FILEPATH);
	m_manage.LoadTexture(O_MOVEMENT, MOVEMENT_PNG_FILEPATH);
	m_manage.LoadTexture(O_LIFE, LIFE_PNG_FILEPATH);
	m_manage.LoadTexture(O_SMARTMON, SMART_MON_PNG_FILEPATH);
	m_manage.LoadTexture(O_REGMON, REGULAR_MON_PNG_FILEPATH);
	m_manage.LoadTexture(O_DATABAR, DATABAR_PNG_FILEPATH);
	m_manage.LoadTexture(O_INFINITY, INFINITY_PNG_FILEPATH);
	m_manage.LoadSound(O_BEGIN, BEGIN_OGG_FILEPATH);
	m_manage.LoadSound(O_GAMEOVER, GAMEOVER_OGG_FILEPATH);
	m_manage.LoadSound(O_YOULOSE, YOU_LOSE_OGG_FILEPATH);
	m_manage.LoadSound(O_YOUWIN, YOU_WIN_OGG_FILEPATH);
	m_manage.LoadSound(O_TIME, TIME_OGG_FILEPATH);
	m_manage.LoadSound(O_WINNER, WINNER_OGG_FILEPATH);
	m_manage.LoadSound(O_VICTORIOUS, VICTORIOUS_OGG_FILEPATH);

}


sf::Text Game::CreateText(const unsigned int& Size, const sf::Font& Font, const sf::Vector2i& Pos, const string & string) const
{
	sf::Text temp;
	temp.setCharacterSize(Size);
	temp.setFont(Font);
	temp.setString(string);
	temp.setColor(sf::Color::Black);
	temp.setPosition(Pos.x, Pos.y);

	return temp;
}