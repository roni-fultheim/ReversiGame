/*
 * Roni Fultheim, ID: 313465965
 * HumanPlayer.cpp
 */


#include <iostream>
#include <limits>
#include "MoveLogic.h"
#include "HumanPlayer.h"

using namespace std;


Location HumanPlayer::getNextMove(ViewGame* view, MoveLogic* logic, Board* board, Player* other)
{
	int row, column;

	//ask the player to insert chosen location in the format (row column), space separated
	view->messageEnterMove();
	cin >> row >> column;

	//input validation
	while (cin.fail()) {
		//clearing stream
		cin.clear();
		//ignoring the rest of the input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//re-asking for move
		view.messageInvalidMove();
		cin >> row >> column;
	}

	//translate to c++ indexing (starting from 0, not 1) and return as location
	return Location (row-1, column-1);
}
