#include "SmartMonster.h"
#include "RegularMonster.h"
#include <cmath>

enum State { PATROL, CHASE };

SmartMonster::SmartMonster(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	: Monsters(texture, pos, size)
{
}

SmartMonster::~SmartMonster()
{
}

sf::Vector2f SmartMonster::SetDirection( float DeltaTime, const sf::Vector2f& destenation)
{
	sf::Vector2f Direction;

	CalcDistance(m_object.getPosition(), destenation);

	if (m_Distance <= CHASE_DISTANCE )
		m_state = CHASE;

	else
		m_state = PATROL;


	switch (m_state)
	{
	case PATROL :
		Direction = RandomMovement(DeltaTime);
		break;

	case CHASE:
		Direction = ChasePlayer(DeltaTime, destenation);
		break;

	default:
		break;
	}

	Animation();
	m_object.setTextureRect(sf::IntRect(m_source.x * SmartMonTileSize.x, m_source.y * SmartMonTileSize.y, SmartMonTileSize.x, SmartMonTileSize.y));

	return Direction;
}

void SmartMonster::CalcDistance(const sf::Vector2f& monster,const sf::Vector2f& player)
{
	m_xDistance = player.x - monster.x;	// Difference between player and monster X axis 
	m_yDistance = player.y - monster.y;	// Difference between player and monster Y axis
	m_Distance = sqrt(pow(m_xDistance, 2) + pow(m_yDistance, 2)); // Calculates the distance from the player
}

sf::Vector2f SmartMonster::ChasePlayer(const float &DeltaTime, const sf::Vector2f& destenation)
{
	float x, y;
	
	if ((int)m_xDistance > 0)
	{
		m_source.y = Right;
		x = SPEED_MONSTER * DeltaTime, y = 0;
	}

	if ((int)m_xDistance < 0)
	{
		m_source.y = Left;
		x = -SPEED_MONSTER * DeltaTime, y = 0;
	}
	
	if((int)m_yDistance > 0)
	{
		m_source.y = Down;
		x = 0, y = SPEED_MONSTER * DeltaTime;
	}

	if ((int)m_yDistance < 0)
	{
		m_source.y = Up;
		x = 0, y = -SPEED_MONSTER * DeltaTime;
	}

	return { x,y };
}