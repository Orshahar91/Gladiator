#include "Objects.h" 



Objects::Objects(const sf::Texture& texture, const sf::Vector2f& pos, const sf::Vector2f& size) : m_isDisposed(false)
	 	// initialize object size 
{

	m_object.setSize(size);
	m_object.setTexture(&texture);	// set object texture
	m_object.setPosition(pos);		// set object position
	m_clock.restart().asMilliseconds();
}

Objects::~Objects()
{
}

void Objects::draw(sf::RenderWindow& window) const
{
	window.draw(m_object);	// draw the object on the board
}

bool Objects::isDisposed()const
{
	return m_isDisposed;
}

sf::FloatRect Objects::getGlobalBounds() const
{
	return m_object.getGlobalBounds();
}

bool Objects::checkCollision(const sf::FloatRect& floatRect) const
{
	//return true;
	return m_object.getGlobalBounds().intersects(floatRect);
}