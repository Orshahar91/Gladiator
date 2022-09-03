#pragma once
#include "Monsters.h" 


class RegularMonster: public Monsters
{
public:
	using Monsters::Monsters;
	~RegularMonster();
protected:

private:
	virtual sf::Vector2f SetDirection( float DeltaTime, const sf::Vector2f& destenation) override;
	
	
};
