#include "Diamond.h"
#include "Digger.h"


Diamond::~Diamond()
{
}

void Diamond::HandleCollision(Objects& obj)
{
	obj.HandleCollision(*this);
}

void Diamond::HandleCollision(Digger& digger)
{
	m_isDisposed = true;
	digger.HandleCollision(*this);
}

void Diamond::HandleCollision(Monsters& monster)
{
}

void Diamond::HandleCollision(Diamond& diamond)
{
}

void Diamond::HandleCollision(Stone& stone)
{
}

void Diamond::HandleCollision(Gift& gift)
{
}

void Diamond::HandleCollision(Wall& wall)
{
}