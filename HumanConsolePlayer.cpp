/*
 * Roni Fultheim, ID: 313465965
 * HumanConsolePlayer.cpp
 */

#include "HumanConsolePlayer.h"
#include <iostream>
#include <limits>

using namespace std;


//constructor calling the parent class's (Player's) constructor
HumanConsolePlayer::HumanConsolePlayer(const std::string& name, const Color& c): Player(name, c) {}


Location HumanConsolePlayer::getNextMove() {
	int row, column;

	//ask the player to insert chosen location in the format (row column), space separated
	cout <<  "Please enter your next move, row then column (separated by space):  ";
	cin >> row >> column;

	//input validation
	while (cin.fail()) {
		//clearing stream
		cin.clear();
		//ignoring the rest of the input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		//re-asking for move
		cout << "Illegal move format. Please enter your next move, row then column (separated by space):  ";
		cin >> row >> column;
	}

	//translate to c++ indexing (starting from 0, not 1) and return as location
	return Location (row-1, column-1);
}
