#include "Monsters.h"

Monsters::Monsters(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size)
	:   Moveables(texture, pos, size)
{
}

Monsters::~Monsters()
{
}

void Monsters::HandleCollision(Objects& obj)
{
	obj.HandleCollision(*this);
}

void Monsters::HandleCollision(Digger& digger)
{

	digger.HandleCollision(*this);
}

void Monsters::HandleCollision(Monsters& monster)
{

}

void Monsters::HandleCollision(Diamond& diamond)
{
}

void Monsters::HandleCollision(Stone& stone)
{
	StopMovement();
}

void Monsters::HandleCollision(Gift& gift)
{
}

void Monsters::HandleCollision(Wall& wall)
{
	StopMovement();
}