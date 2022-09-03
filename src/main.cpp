#include <SFML/Graphics.hpp>
#include <ctime>
#include "Game.h"
#include "Menu.h"



int main()
{
	srand(time(NULL));
	Game game;
	game.Run();

	return EXIT_SUCCESS;

}