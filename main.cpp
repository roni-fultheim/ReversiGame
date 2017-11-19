/*
 * Roni Fultheim, ID: 313465965
 *
 * main.cpp
 * Implementation of main function - runs program
 */

#include <iostream>
#include "GameManager.h"
#include "HumanPlayer.h"
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
	Player* p1 = new HumanPlayer("X", Player::ColorOfPlayer::BLACK);
	Player* p2 = new HumanPlayer("O", Player::ColorOfPlayer::WHITE);

	//allocate on stack
	//currently there is only one type of logic - no need to allocate dynamically
	StandardMoveLogic ml;
	ViewByConsole v;
	GameManager gf(b, p1, p2, &ml);

	//play game
	gf.playGame();

	//release memory
	delete b;
	delete p1;
	delete p2;


	return 0;
}
