#pragma once
#include "Moveables.h"
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Monsters.h"



class Digger:public Moveables
{
public:
	Digger(const int & Score ,const int & Life ,const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size);
	~Digger();
	void setStartingPosition(const sf::Vector2f& pos);
	sf::Vector2f GetPosition() const;
	void reset();
	int GetLife() const;
	int GetScore() const;
	void AddScore(const int &score);
	int Getstone() const;
	void SetDiamonds(const int &num);
	int GetDiamonds() const;

	virtual void HandleCollision(Objects& obj) override;
	virtual void HandleCollision(Digger& digger) override;
	virtual void HandleCollision(Monsters& monster) override;
	virtual void HandleCollision(Diamond& diamond) override;
	virtual void HandleCollision(Stone& stone) override;
	virtual void HandleCollision(Gift& gift) override;
	virtual void HandleCollision(Wall& wall) override;

	void SetStone(const int& Stones);

	float GetTime() const;

	void InitTime();

	void DecreaseLife();

	void SetLimitedTime(const bool& is_on);

protected:


private:
	virtual sf::Vector2f SetDirection( float DeltaTime, const sf::Vector2f& destenation) override;




	int m_Life,
		m_Score,
		m_Stone,
		m_Time,
		m_Num_Of_Diamonds;

	bool m_IsLimitedTime;

};


