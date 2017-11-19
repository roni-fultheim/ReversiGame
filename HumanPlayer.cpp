/*
 * Roni Fultheim, ID: 313465965
 * HumanPlayer.cpp
 */

#include "HumanPlayer.h"
#include <iostream>
#include <limits>

using namespace std;


//constructor calling the parent class's (Player's) constructor
HumanPlayer::HumanPlayer(const std::string& name, const Player::ColorOfPlayer& c): Player(name, c) {}


Location HumanPlayer::getNextMove(const ViewGame& v, const MoveLogic& logic, const Board& b, const Player& other) {
	int row, column;

	//ask the player to insert chosen location in the format (row column), space separated
	v.messageEnterMove();
	cin >> row >> column;

	//input validation
	while (cin.fail()) {
		//clearing stream
		cin.clear();
		//ignoring the rest of the input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//re-asking for move
		v.messageInvalidMove();
		cin >> row >> column;
	}

	//translate to c++ indexing (starting from 0, not 1) and return as location
	return Location (row-1, column-1);
}
