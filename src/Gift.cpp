#include "Gift.h"



Gift::~Gift()
{
}

void Gift::HandleCollision(Objects& obj)
{
	obj.HandleCollision(*this);
}

void Gift::HandleCollision(Digger& digger)
{
	m_isDisposed = true;
	digger.HandleCollision(*this);
}

void Gift::HandleCollision(Monsters& monster)
{
}

void Gift::HandleCollision(Diamond& diamond)
{
}

void Gift::HandleCollision(Stone& stone)
{
}

void Gift::HandleCollision(Gift& gift)
{
}

void Gift::HandleCollision(Wall& wall)
{
}