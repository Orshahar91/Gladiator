#pragma once
#include "Objects.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
class Moveables : public Objects
{
public:
	Moveables(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	~Moveables();
	void reset();
	void move(float DeltaTime, const sf::Vector2f &Destenation, const sf::RectangleShape& board);
	bool is_valid(const sf::RectangleShape& board)const; 

protected:
	void StopMovement() ;
	void Animation();
	sf::Vector2f RandomMovement(float& DeltaTime);
	sf::Vector2f m_startingPosition;
	sf::Vector2f m_direction;
	virtual sf::Vector2f SetDirection( float DeltaTime, const sf::Vector2f& destenation) = 0 ;
	float animationCounter, animationFrameDuration;
	sf::Vector2i m_source;
	bool m_moved;

private:
	unsigned m_randMov = rand() % 4;
	sf::Clock m_RandClock;
};
