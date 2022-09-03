#pragma once

#include <string>
#include <map>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Globals.h"

class Asset_Manager
{
public:
	Asset_Manager();
	~Asset_Manager();

	void LoadTexture(const int name, const std::string FileName);
	sf::Texture& GetTexture(const int name) ;

	void LoadFont(const int name, const std::string FileName);
	sf::Font& GetFont(const int name);

	void LoadSound(const int name, const std::string FileName);
	sf::SoundBuffer& GetSound(const int name);


private:
	std::map<int, sf::Texture> m_textures; // map to texture load and extraction
	std::map<int, sf::Font> m_fonts; // map to font load and extraction
	std::map<int, sf::SoundBuffer> m_sounds; // map to sound load and extraction
	sf::Context context; // to use openGL functions without an active window
};
