#pragma once
#include "Asset_Manager.h"
#include "Board.h"
#include "Menu.h"
#include "DataBar.h"
#include "Globals.h"
#include <fstream>

class Game
{
public:
	Game();
	~Game();
	void Run();

	void Sounds(sf::Sound &Sound, const int& name, const int& Volume, const bool& loop);

private:
	void LoadLevel();
	void LoadTextures();
	sf::Text CreateText(const unsigned int& Size, const sf::Font& Font, const sf::Vector2i& Pos, const string &) const;
	void Draw();
	void HandleEvents();
	void DisplayMsg(const sf::Text &);

	bool GameCompleted;
	Board m_Board;
	Asset_Manager m_manage;
	Menu m_menu;
	sf::RenderWindow  m_Window;
	fstream m_myfile;
	sf::Clock m_Clock;


};
