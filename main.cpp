/*
 * Roni Fultheim, ID: 313465965
 *
 * main.cpp
 * Implementation of main function - runs program
 */

#include <iostream>
#include "GameFlow.h"
#include "HumanConsolePlayer.h"
#include "StandardMoveLogic.h"
#include "Color.h"
#include <string>

using namespace std;

/**
 * Creates a Board initialized by default parameters and prints it
 */
int main() {
	//initialize game
	cout << "Welcome to Reversi!" << endl;

	//dynamically allocate objects of general types on heap
	Board* b = new Board();
	Player* p1 = new HumanConsolePlayer("X", BLACK);
	Player* p2 = new HumanConsolePlayer("O", WHITE);

	//allocate on stack
	//currently there is only one type of logic - no need to allocate dynamically
	StandardMoveLogic ml;
	GameFlow gf(b, p1, p2, &ml);

	//play game
	gf.playGame();

	//release memory
	delete b;
	delete p1;
	delete p2;


	return 0;
}
