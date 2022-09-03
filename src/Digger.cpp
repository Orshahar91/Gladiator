#include "Digger.h"

Digger::Digger(const int &Score,const int &Life, const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	 :m_IsLimitedTime(false), m_Time(0), m_Score(Score), m_Life(Life), Moveables(texture, pos, size)
{
	
}

Digger::~Digger()
{
}

void Digger::setStartingPosition(const sf::Vector2f& pos)
{
	m_startingPosition = pos;	// set the new starting position
	m_object.setPosition(pos);	// and also move the object
	m_clock.restart().asMilliseconds();
	
}

sf::Vector2f Digger:: GetPosition() const
{
	return m_object.getPosition();
}

void Digger::reset()
{
	Moveables::reset();			// use the Moveables reset
}

int Digger::GetLife() const
{
	return m_Life;
}

int Digger::GetScore()  const
{
	return m_Score;
}

void Digger::AddScore(const int &score)
{
	m_Score += score;
}

int Digger::Getstone() const
{
	return m_Stone;
}

void Digger::SetDiamonds(const int & num)
{
	m_Num_Of_Diamonds = num;
}

int Digger::GetDiamonds() const
{
	return m_Num_Of_Diamonds;
}

sf::Vector2f Digger::SetDirection(float DeltaTime, const sf::Vector2f& destenation)
{
	float x = 0, y = 0;
	 m_moved = false;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		m_source.y = Up;
		x = 0, y = -SPEED * DeltaTime;
		m_moved = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		m_source.y = Down;
		x = 0, y = SPEED * DeltaTime;
		m_moved = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		m_source.y = Left;
		x = -SPEED * DeltaTime, y = 0;
		m_moved = true;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		m_source.y = Right;
		x = SPEED * DeltaTime, y = 0;
		m_moved = true;
	}

	Animation();

	m_object.setTextureRect(sf::IntRect(m_source.x * DiggerTileSize.x, m_source.y * DiggerTileSize.y, DiggerTileSize.x, DiggerTileSize.y));
	


	return { x,y };
}

void Digger::SetLimitedTime(const bool &is_on)
{
	m_IsLimitedTime = is_on;
}

void Digger::HandleCollision(Objects& obj)
{
	obj.HandleCollision(*this);
}

void Digger::HandleCollision(Digger& digger)
{
	
}

void Digger::HandleCollision(Monsters& monster)
{
	
	m_Life--;
	if (m_Life <= 0)
	{
		m_isDisposed = true;
	}
		

	else
	{
		monster.reset();
		reset();
	}
}

void Digger::HandleCollision(Diamond& diamond)
{
	m_Score += SCORE_DIAMOND;
	m_Num_Of_Diamonds--;

}

void Digger::HandleCollision(Stone& stone)
{
	m_Stone--;
}

void Digger::HandleCollision(Gift& gift)
{
	int prize;

	if (m_IsLimitedTime)
		prize = rand() % 3; // if there's a time limit in the level

	else
		prize = rand() % 2; // if there's no time limit don't roll '2' for the prize

	switch (prize)
	{
	case 0:
		m_Stone++;
		break;
	case 1:
		m_Score +=  SCORE_DIAMOND;
		break;
	case 2:
		m_Time = BONUS_TIME;
		break;

	default:
		break;
	}

}

void Digger::HandleCollision(Wall& wall)
{
	StopMovement();
}

void Digger::SetStone(const int& Stones)
{
	m_Stone = Stones;

}

float Digger::GetTime() const
{
	return m_Time;

}

void Digger::InitTime()
{
	m_Time = 0;
}

void Digger::DecreaseLife()
{
	m_Life--;
	if (m_Life <= 0)
	{
		m_isDisposed = true;
	}

}