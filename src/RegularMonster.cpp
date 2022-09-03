#include "RegularMonster.h"


RegularMonster::~RegularMonster()
{
}

sf::Vector2f RegularMonster::SetDirection( float DeltaTime, const sf::Vector2f& destenation)
{
	sf::Vector2f Direction;

	Direction = RandomMovement(DeltaTime);


	Animation(); // Animate movement
	m_object.setTextureRect(sf::IntRect(m_source.x * RegMonTileSize.x, m_source.y * RegMonTileSize.y, RegMonTileSize.x, RegMonTileSize.y));
	return Direction; // return direction of movement
}