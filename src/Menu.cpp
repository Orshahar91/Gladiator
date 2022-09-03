#include "Menu.h"
using sf::Event;

Menu::Menu()
{

}

void Menu::Draw(sf::RenderWindow &window,bool &start, Asset_Manager &manage)
{
	m_background.setSize({SCREEN_WIDTH, SCREEN_HEIGHT});	// set background as the size of the window
	m_background.setTexture(&manage.GetTexture(O_MENU));

	sf::Vector2f button_pos = window.getView().getCenter();
	button_pos.y = button_pos.y - BUTTON_CORRECTION;

	m_PlayBut = (std::make_unique<Button>(manage.GetTexture(O_START_BUT), button_pos, manage.GetSound(O_START)));
	m_ExitBut = (std::make_unique<Button>(manage.GetTexture(O_EXIT_BUT), sf::Vector2f(m_PlayBut->GetPosition().x, m_PlayBut->GetPosition().y + (BUTTON_SIZE)), manage.GetSound(O_QUIT)));

	while (window.isOpen())
	{
		window.clear();
		window.draw(m_background);
		m_PlayBut->draw(window);
		m_ExitBut->draw(window);
		window.display();
		HandleMouseClick(window,start);
		if(start)
	    return;
	}
}

void Menu::HandleMouseClick(sf::RenderWindow &window,bool &start)
{
	 Event event;
	  sf::Vector2f mousePos;
	if (window.waitEvent(event))
	{
		switch (event.type)
		{
		case Event::Closed:
			window.close();
			break;
		case Event::MouseButtonPressed:
			if (event.mouseButton.button == sf::Mouse::Button::Left)
			{
				mousePos = window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
			}
			if (m_ExitBut->Contains(mousePos))
				window.close();
			else if (m_PlayBut->Contains(mousePos))
			{
				m_PlayBut->StopSound();
	
				start = true;
				return;
			}
			break;
		case Event::MouseMoved:
			mousePos = window.mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });

			if (m_PlayBut->Contains(mousePos))	// if mouse hover the play button
				m_PlayBut->highlight();		// highlight the play button
			else
				m_PlayBut->unhighlight();

			if (m_ExitBut->Contains(mousePos))	// if mouse hover the exit button
				m_ExitBut->highlight();	// highlight the exit button
			else
				m_ExitBut->unhighlight();

			break;
		}
	}
}

