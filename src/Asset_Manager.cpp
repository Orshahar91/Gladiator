#include "Asset_Manager.h"

Asset_Manager::Asset_Manager()
{
}

Asset_Manager::~Asset_Manager()
{
}

void Asset_Manager::LoadTexture(const int name, const std::string FileName) 
{
	sf::Texture tex;

	if (tex.loadFromFile(FileName))
	{
		this->m_textures[name] = tex;
	}
}

sf::Texture& Asset_Manager::GetTexture(const int name) 
{
	return this->m_textures.at(name);
}

void Asset_Manager::LoadFont(const int name, const std::string FileName)
{
	sf::Font font;

	if (font.loadFromFile(FileName))
	{
		this->m_fonts[name] = font;
	}
}

sf::Font& Asset_Manager::GetFont(const int name)
{
	return this->m_fonts.at(name);
}

void Asset_Manager::LoadSound(const int name, const std::string FileName)
{
	sf::SoundBuffer sound;

	if (sound.loadFromFile(FileName))
	{
		this->m_sounds[name] = sound;
	}
}

sf::SoundBuffer& Asset_Manager::GetSound(const int name)
{
	return this->m_sounds.at(name);
}

