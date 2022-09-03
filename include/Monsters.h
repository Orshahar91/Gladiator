#pragma once
#include "Moveables.h"
#include "Digger.h"

class Monsters: public Moveables
{
public:
	Monsters(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	~Monsters();

	virtual void HandleCollision(Objects& obj) override;
	virtual void HandleCollision(Digger& digger) override;
	virtual void HandleCollision(Monsters& monster) override;
	virtual void HandleCollision(Diamond& diamond) override;
	virtual void HandleCollision(Stone& stone) override;
	virtual void HandleCollision(Gift& gift) override;
	virtual void HandleCollision(Wall& wall) override;

protected:

private:

};
