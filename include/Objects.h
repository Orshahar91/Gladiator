#pragma once
#include <SFML/Graphics.hpp>

class Digger;
class Monsters;
class Diamond;
class Stone;
class Gift;
class Wall;


class Objects
{
public:
	Objects(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);

	~Objects();

	void draw(sf::RenderWindow& window) const;

	

	sf::FloatRect getGlobalBounds() const;

	bool checkCollision(const sf::FloatRect& floatRect) const;

	bool isDisposed() const;

	virtual void HandleCollision(Objects& obj) = 0;
	virtual void HandleCollision(Digger& digger) = 0;
	virtual void HandleCollision(Monsters& monster) = 0;
	virtual void HandleCollision(Diamond& diamond) = 0;
	virtual void HandleCollision(Stone& stone) = 0;
	virtual void HandleCollision(Gift& gift) = 0;
	virtual void HandleCollision(Wall& wall) = 0;


protected:
	
	sf::RectangleShape m_object;
	sf::Clock m_clock;
	bool m_isDisposed;


private:
	

};
