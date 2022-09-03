#include "Button.h"

Button::Button(const sf::Texture &texture, const sf::Vector2f &pos, const sf::SoundBuffer & soundbuff)
{
	// Initialize button with:
	m_button.setTexture(&texture);	// texture
	m_button.setPosition(pos);				// position

	m_button.setSize(ButtonSize);
	m_button.setOrigin(m_button.getGlobalBounds().width / 2, m_button.getGlobalBounds().height / 2);	// set origin to the middle


	m_sound.setBuffer(soundbuff);
	
}



void Button::draw(sf::RenderWindow& window)
{
	window.draw(m_button);
}


sf::Vector2f Button::GetPosition() const
{
	return m_button.getPosition();
}

bool Button::Contains(const sf::Vector2f &mousePos) const
{
	return m_button.getGlobalBounds().contains(mousePos);
	
}


void Button::highlight()
{
	m_button.setFillColor(sf::Color::Magenta);	// paint the button
	m_sound.play();
}

void Button::unhighlight()
{
	m_button.setFillColor(sf::Color::White);	// set color back to default
	m_sound.stop();
}

void Button::StopSound()
{
	m_sound.stop();
}