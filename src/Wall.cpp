#include "Wall.h"


Wall::~Wall()
{
}

void Wall::HandleCollision(Objects& obj)
{
	obj.HandleCollision(*this);
}

void Wall::HandleCollision(Digger& digger)
{
	digger.HandleCollision(*this);

}

void Wall::HandleCollision(Monsters& monster)
{
	monster.HandleCollision(*this);
}

void Wall::HandleCollision(Diamond& diamond)
{
}

void Wall::HandleCollision(Stone& stone)
{

}

void Wall::HandleCollision(Gift& gift)
{
}

void Wall::HandleCollision(Wall& wall)
{
}
