#include "Stone.h"


Stone::~Stone()
{
}

void Stone::HandleCollision(Objects& obj)
{
	obj.HandleCollision(*this);
}

void Stone::HandleCollision(Digger& digger)
{
	m_isDisposed = true;
	digger.HandleCollision(*this);
}

void Stone::HandleCollision(Monsters& monster)
{
	monster.HandleCollision(*this);
}

void Stone::HandleCollision(Diamond& diamond)
{
}

void Stone::HandleCollision(Stone& stone)
{

}

void Stone::HandleCollision(Gift& gift)
{
}

void Stone::HandleCollision(Wall& wall)
{
}