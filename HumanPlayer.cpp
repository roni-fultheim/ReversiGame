/*
 * HumanPlayer.cpp
 *
 *  Created on: Oct 27, 2017
 *      Author: yael
 */
#include "HumanPlayer.h"

#include <iostream>
using namespace std;


HumanPlayer::HumanPlayer(ColourOfPlayer color):Player(color){}

bool HumanPlayer::validInput (Point &point)
{
	bool validInput = false;
	int row;
	int col;
	// while the input is not valid - keep asking for valid one
	while(!validInput)
	{
		cin >> row;
		cin >> col;
		//if the input type is not int - insert again
		if(cin.fail())
		{
			cout << "Invalid input. Please insert integers numbers" << endl;
			cin.clear();
			cin.ignore();
		}
		else
		{
			// the input is valid
			validInput = true;
			point.x = row;
			point.y = col;
		}
		return validInput;
	}
}

int HumanPlayer::moveByChoice(vector<Point> &possibleMoves, Point &point)
{
	// size of the vector which represent the possible moves
	int possibleMovesSize = possibleMoves.size();

	//check that the selected point is in the vector.
	//also, update the index to be the position of the point in the vector.
	for (int i=0; i<possibleMovesSize; ++i)
	{
		if(point == possibleMoves[i])
		{
			return i;
		}
	}
	//if not found
	return -1;
}
