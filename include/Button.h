#pragma once
#include <SFML/Graphics.hpp>
#include "Globals.h"
#include "Asset_Manager.h"
#include <SFML/Audio.hpp>

class Button
{
public:
	Button(const sf::Texture &, const sf::Vector2f& pos, const sf::SoundBuffer&);


	void draw(sf::RenderWindow& window);
	sf::Vector2f GetPosition() const;
	bool Contains(const sf::Vector2f &) const;
	void highlight();
	void unhighlight();
	void StopSound();

private:
	sf::RectangleShape m_button;
	sf::Sound m_sound;

};
