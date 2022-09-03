#pragma once
#include <Asset_Manager.h>
#include <fstream>
#include "Objects.h"
#include "Statics.h"
#include "Monsters.h"
#include "Digger.h"
#include <string>
#include "Wall.h"
#include "Diamond.h"
#include "Stone.h"
#include "Gift.h"
#include "SmartMonster.h"
#include "RegularMonster.h"
#include "DataBar.h"
#include <experimental/vector>


using std::unique_ptr;
using std::vector;

class Board
{
public:
	Board(); // c-tor
	~Board(); // d-tor

	void Clear_Board(); // clears the board from the objects(monsters and statics)
	void ReleaseDigger(); // clears the digger ptr
	void LoadBoard(Asset_Manager& manage,std::fstream& file, const unsigned &rows, const unsigned &cols, const int&, const float &time); // Read the level and set the level's objects
	void Create();  // set's the board's rectangle shape size and position
	void draw(sf::RenderWindow& window); // draws the objects to the SFML's window
	void DrawDataBar(sf::RenderWindow &); // Draws the databar
	void IncreaseLevel(); // increase the game's level
	void move_moveables(); // moving the object's on the board
	void UpdateDataBar(); // updates the databar
	void ResetLevel(); // reset the level counter of the game
	bool GameOver(); // return's a boolean value to determine wether the game is over.

	bool LevelCompleted() const; // return's if the current level is completed

	void GameStats(); // handles the game's status

	void SetInfinity(const bool &); // sets infinite time on the databar

private:

	void Restart(); // reset's the monsters and digger

	void addMonster(const sf::Texture&, const sf::Texture&, const sf::Vector2f&, const sf::Vector2f& size); // add monster to the game(regular or smart)

	void handleCollisions(Objects& Object); // double dispatch

	

	int m_Stones,
		m_OriginalStones,
		m_Timer, // To set the time for the data bar
		m_score,
		m_level,
		m_Time, // to save time from the board
		m_OriginalTime, 
		m_Num_Of_Diamonds, // counter for the diamonds in each level
		m_life;

	bool m_LevelCompleted; // boolean to check if the level is over


	unique_ptr<Digger> m_Digger;		// Digger instance
	vector<unique_ptr<Monsters>> m_monsters;	// Vector of Monsters
	vector<unique_ptr<Statics>> m_statics;	// Vector of statics

	DataBar m_DataBar; // Data bar instance
	sf::RectangleShape m_board; // Rectangle shape for the Board 

	sf::Clock m_GameClock; // game clock
	sf::Sound m_timeAU;
	sf::Sound m_youloseAU;
	sf::Sound m_youwinAU;
};
