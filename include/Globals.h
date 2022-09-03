#pragma once
#include <SFML/Graphics.hpp>

#include <string>
using std::string;

const string LIFE_PNG_FILEPATH = "Life.png";
const string GIFT_PNG_FILEPATH = "Gift.png";
const string STONE_PNG_FILEPATH = "Stone.png";
const string DIAMOND_PNG_FILEPATH = "Diamond.png";
const string WALL_PNG_FILEPATH = "Wall.jpg";
const string MENU_PNG_FILEPATH = "Menu.jpg";
const string FONT_TTF_FILEPATH = "FontRoman.ttf";
const string ARENA_PNG_FILEPATH = "Arena.png";
const string START_OGG_FILEPATH = "prepare_yourself.ogg";
const string QUIT_OGG_FILEPATH = "loser.ogg";
const string BEGIN_OGG_FILEPATH = "begin.ogg";
const string GAMEOVER_OGG_FILEPATH = "game_over.ogg";
const string TIME_OGG_FILEPATH = "time.ogg"; 
const string WINNER_OGG_FILEPATH = "winner.ogg";
const string YOU_LOSE_OGG_FILEPATH = "you_lose.ogg";
const string YOU_WIN_OGG_FILEPATH = "you_win.ogg";
const string MUSIC_OGG_FILEPATH = "GameMusic.ogg";
const string START_PNG_FILEPATH = "Start.png";
const string DATABAR_PNG_FILEPATH = "DataBar.png";
const string EXIT_PNG_FILEPATH = "Exit.png";
const string MOVEMENT_PNG_FILEPATH = "Digger.png";
const string SMART_MON_PNG_FILEPATH = "SmartMonster.png";
const string REGULAR_MON_PNG_FILEPATH = "RegularMonster.png";
const string INFINITY_PNG_FILEPATH = "Infinity.png";
const string VICTORIOUS_OGG_FILEPATH = "Victory.ogg";

const unsigned  SCREEN_WIDTH = 1920;
const unsigned  SCREEN_HEIGHT = 1080;

const string APP_NAME = "Gladigger";
const string FILE_NAME = "Board.txt";

const unsigned DATABAR_HEIGHT = 100;
const unsigned ICON_SIZE = 50;

const unsigned BUTTON_SIZE = 150;
const unsigned CHASE_DISTANCE = 400.f;
const unsigned SCORE_DIAMOND = 15;
const unsigned SCORE_LEVEL = 20;
const unsigned BONUS_TIME = 10;
const int LIFE = 3;
const int SCORE = 0;

const unsigned BUTTON_CORRECTION = 150;


const sf::Vector2i TXTTIME_POS = { 1780,0 };
const sf::Vector2i TXTLEVEL_POS = { 275,0 };
const sf::Vector2i TXTSTONE_POS = { 1450,0 };
const sf::Vector2i TXTSCORE_POS = { 1000,0 };
const sf::Vector2i ICONLIFE_POS = { 560,0 };
const sf::Vector2i ICONINFINITY_POS = { TXTTIME_POS.x,25 };
const sf::Vector2i TXT_MSG_POS = { 125, 350 };

const sf::Vector2i RegMonTileSize = {33,55};
const sf::Vector2i SmartMonTileSize = {44,50};
const sf::Vector2i DiggerTileSize = {39,57};

const bool LOOP_ON = true;
const bool LOOP_OFF = false;

const unsigned MUSIC_VOL = 50;
const unsigned FULL_VOL = 100;

const unsigned DES_OF_LIVE = 40;

const unsigned FontSize = 80;
const unsigned MsgSize = 200;

const float SPEED = 400;
const float SPEED_MONSTER = 100.f;

const sf::Vector2f BoardSize = { SCREEN_WIDTH , SCREEN_HEIGHT - DATABAR_HEIGHT };
const sf::Vector2f BoardPos = { 0.f, DATABAR_HEIGHT };
const sf::Vector2f ButtonSize = { 400, 100 };

// Enum for each object by his char representation.
enum Char_t
{
	C_EMPTY = ' ', C_DIGGER = '/', C_WALL = '#', C_MONSTER = '!', C_DIAMOND = 'D', C_STONE = '@', C_GIFT = '+', C_STONE_AND_GIFT = '$'
};

// Enum for each object in the project. 
enum Object_t
{
	O_STONE, O_WALL, O_DIAMOND, O_MENU, O_FONT, O_ARENA, O_GIFT, O_DATABAR, O_INFINITY, O_MUSIC, O_BEGIN, O_GAMEOVER, O_TIME,O_WINNER, O_YOULOSE,
	O_START, O_QUIT, O_START_BUT, O_EXIT_BUT, O_MOVEMENT, O_LIFE, O_SMARTMON, O_REGMON, O_YOUWIN, O_VICTORIOUS
};

enum Direction{Up, Left, Down, Right};
