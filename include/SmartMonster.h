#pragma once
#include "Monsters.h"
#include <SFML/Graphics.hpp>

class SmartMonster:public Monsters
{
public:
	SmartMonster(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	~SmartMonster();
protected:

private:
	virtual sf::Vector2f SetDirection( float DeltaTime, const sf::Vector2f& destenation) override;
	void CalcDistance(const sf::Vector2f & ,const sf::Vector2f&);

	sf::Vector2f ChasePlayer(const float &DeltaTime, const sf::Vector2f&);

	float m_xDistance;
	float m_yDistance;
	float m_Distance;
	int m_state;
};

