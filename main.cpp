/*
 * main.cpp
 *
 *  313297897
 *  Author: Yael Hacmon
 */



#include "ReversiGame.h"

int main()
{
	GameManger* game = new ReversiGame();
	game->play();
	delete game;
	return 0;
}
