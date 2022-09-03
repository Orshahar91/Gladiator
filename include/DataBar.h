#pragma once
#include <SFML/Graphics.hpp>
#include "Asset_Manager.h"
#include <string>

class DataBar
{
public:
	DataBar();
	void Draw(sf::RenderWindow &);
	void LoadBar(Asset_Manager& manage);
	void SetLife(const int&);
	void SetTimer(const float&);
	float GetTimer() const;
	void AddTime(const float &time);
	void SetScore(const int&);
	void AddScore(const int&);
	void SetStones(const int&);
	void SetLevel(const int&);


	


	~DataBar();

	sf::RectangleShape CreateRect(const sf::Vector2f&, const sf::Texture&, const sf::Vector2i&);

	sf::Text CreateText(const unsigned int& Size, const sf::Font& Font, const sf::Vector2i& Pos);

	void SetInfiniteTime(const bool& is_infinite);

private:
	void DrawDataBar(sf::RenderWindow&);
	void DrawLevel(sf::RenderWindow&);
	void DrawScore(sf::RenderWindow&);
	void DrawLife(sf::RenderWindow&);
	void DrawStones(sf::RenderWindow&);
	void DrawTimer(sf::RenderWindow&);

	int m_level,
		m_score,
		m_life,
		m_stones;

	float m_timer;

	bool m_InfiniteTime;

	sf::RectangleShape m_DataWindow;
	sf::RectangleShape m_InfinityIcon;
	sf::RectangleShape m_LifeIcon;

	sf::Text m_TxtLife;
	sf::Text m_TxtScore;
	sf::Text m_TxtStones;
	sf::Text m_TxtLevel;
	sf::Text m_TxtTime;

	sf::Clock m_Clock;
};
