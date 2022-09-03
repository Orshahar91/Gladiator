#include "DataBar.h"

DataBar::DataBar() : m_life(0) , m_InfiniteTime(false)
{

}

void DataBar::LoadBar(Asset_Manager& manage)
{
	m_DataWindow = CreateRect({ SCREEN_WIDTH, DATABAR_HEIGHT }, manage.GetTexture(O_DATABAR), { 0,0 });
	m_LifeIcon = CreateRect({ ICON_SIZE, ICON_SIZE }, manage.GetTexture(O_LIFE), ICONLIFE_POS);
	m_InfinityIcon = CreateRect({ ICON_SIZE, ICON_SIZE }, manage.GetTexture(O_INFINITY), ICONINFINITY_POS);

	m_TxtStones = CreateText(FontSize, manage.GetFont(O_FONT), TXTSTONE_POS);
	m_TxtTime = CreateText(FontSize, manage.GetFont(O_FONT), TXTTIME_POS);
	m_TxtLevel = CreateText(FontSize, manage.GetFont(O_FONT), TXTLEVEL_POS);
	m_TxtScore = CreateText(FontSize, manage.GetFont(O_FONT), TXTSCORE_POS);
	
}



void DataBar::SetLife(const int&life)
{
	m_life = life;
}



void DataBar::SetTimer(const float &time)
{
	m_Clock.restart();
	m_timer = time;
}

float DataBar::GetTimer()const
{
	return m_timer;
}

void DataBar::AddTime(const float &time)
{
	m_timer += time;
}

void DataBar::SetScore(const int&score)
{
	m_score = score;
}



void DataBar::AddScore(const int &bonus)
{
	m_score += bonus;
}

void DataBar::SetStones(const int&stones)
{
	m_stones = stones;
}

void DataBar::SetLevel(const int &level)
{
	m_level = level;
}

void DataBar::DrawLevel(sf::RenderWindow&window)
{
	m_TxtLevel.setString(std::to_string((int)m_level));
	window.draw(m_TxtLevel);
}

void DataBar::DrawDataBar(sf::RenderWindow& window)
{
	window.draw(m_DataWindow);
}

void DataBar::DrawScore(sf::RenderWindow&window)
{
	m_TxtScore.setString(std::to_string((int)m_score));
	window.draw(m_TxtScore);
}

void DataBar::DrawLife(sf::RenderWindow&window)
{

	for (int i = 0; i < m_life; i++)
	{
		m_LifeIcon.setPosition(ICONLIFE_POS.x+(i* DES_OF_LIVE), 20);
		window.draw(m_LifeIcon);	
	}
	
}

void DataBar::DrawStones(sf::RenderWindow&window)
{
	
	m_TxtStones.setString(std::to_string(int(m_stones)));
	window.draw(m_TxtStones);
}

void DataBar::DrawTimer(sf::RenderWindow&window)
{
	if (m_InfiniteTime)
		window.draw(m_InfinityIcon);

	else
	{
		float dt = m_Clock.restart().asSeconds();
		m_timer -= dt;
		m_TxtTime.setString(std::to_string(int(m_timer)));
		window.draw(m_TxtTime);
	}
}

void DataBar::Draw(sf::RenderWindow&window)
{
	DrawDataBar(window);
	DrawLevel(window);
	DrawScore(window);
	DrawLife(window);
	DrawStones(window);
	DrawTimer(window);
}

DataBar::~DataBar()
{
}

sf::RectangleShape DataBar::CreateRect(const sf::Vector2f& Size, const sf::Texture& Tex, const sf::Vector2i& Pos)
{

	sf::RectangleShape temp;
	temp.setSize(Size);
	temp.setTexture(&Tex);
	temp.setPosition(Pos.x,Pos.y);

	return temp;
}

sf::Text DataBar::CreateText(const unsigned int& Size, const sf::Font& Font, const sf::Vector2i & Pos)
{

	sf::Text temp;
	temp.setCharacterSize(Size);
	temp.setFont(Font);
	temp.setPosition(Pos.x, Pos.y);

	return temp;
}

void DataBar::SetInfiniteTime(const bool & is_infinite)
{
	m_InfiniteTime = is_infinite;
}