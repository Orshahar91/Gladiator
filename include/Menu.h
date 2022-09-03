#pragma once
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "Globals.h"
#include "Asset_Manager.h"
#include <SFML/Audio.hpp>
#include <experimental/vector>
using namespace std;


class Menu
{
public:
	Menu();
	void Draw(sf::RenderWindow& window,bool &, Asset_Manager& manage);
protected:

private:
	void HandleMouseClick(sf::RenderWindow &, bool &);
	unique_ptr<Button> m_PlayBut;
	unique_ptr<Button> m_ExitBut;
	sf::RectangleShape m_background;

};

