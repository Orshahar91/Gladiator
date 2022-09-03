#include "Moveables.h"


Moveables::Moveables(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:m_source(Up, Down), animationCounter(0), animationFrameDuration(150), Objects(texture, pos, size), m_startingPosition(pos)
{
}

Moveables::~Moveables()
{
}

void Moveables::reset()
{
	m_isDisposed = false;
	m_object.setPosition(m_startingPosition);
}

void Moveables::move(float DeltaTime, const sf::Vector2f &Destenation, const sf::RectangleShape & board)
{
	m_direction = SetDirection(DeltaTime, Destenation);
	m_object.move(m_direction);
		
	if (!is_valid(board))
		StopMovement();
}

bool Moveables::is_valid(const sf::RectangleShape& board) const
{
	if (m_object.getPosition().x < 0 || m_object.getPosition().y <DATABAR_HEIGHT ||  // check if reached the databar or left edge of the screen
		m_object.getPosition().x > (board.getSize().x - m_object.getSize().x) ||   //  check if reached right edge of the board
		m_object.getPosition().y > (board.getSize().y) - m_object.getSize().y + DATABAR_HEIGHT)
		return false;

	return true;
}

void Moveables::StopMovement() 
{
	m_object.move(-m_direction);
}

void Moveables::Animation()
{
	if (!m_moved)
		animationCounter = 0;

	animationCounter += m_clock.restart().asMilliseconds();

	if (animationCounter >= animationFrameDuration && (m_moved))
	{
		animationCounter -= animationFrameDuration;
		m_source.x++;

		if (m_source.x >= 9)
			m_source.x = 0;
	}

}

sf::Vector2f Moveables::RandomMovement(float & DeltaTime)
{
	float x, y;

	if (m_RandClock.getElapsedTime().asSeconds() >= 2)
	{
		m_randMov = rand() % 4;	// generate a random number 0 - 3
		m_RandClock.restart().asSeconds();
	}

	if (m_randMov == 0)	// if 0 - move monster up
	{
		x = 0, y = -SPEED_MONSTER * DeltaTime;
		m_source.y = Up;
	}

	if (m_randMov == 1)	// if 1 - move monster down
	{
		x = 0, y = SPEED_MONSTER * DeltaTime;
		m_source.y = Down;
	}

	if (m_randMov == 2)	// if 2 - move monster left
	{
		x = -SPEED_MONSTER * DeltaTime, y = 0;
		m_source.y = Left;
	}

	if (m_randMov == 3)	// if 3 - move monster right
	{
		m_source.y = Right;
		x = SPEED_MONSTER * DeltaTime, y = 0;
	}

	return { x,y };
}