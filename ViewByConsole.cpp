/*
 * Yael Hacmon, ID 313597897
 * Roni Fultheim, ID 313465965
 */

#include "ViewByConsole.h"
#include <iostream>
#include <string>
using namespace std;

void ViewByConsole::printBoard(Board::ElementInBoard** board, int sizeOfBoard) const
{
	//print the indexes of the columns
	cout << " | ";
	for(int i=1; i<=sizeOfBoard ;++i)
	{
		cout << i << " | ";
	}
	cout << endl;
	// print spaces line
	cout << "----------------------------------" << endl;
	// print the content of the board
	for(int i=0; i<sizeOfBoard ;++i)
	{
		// the index of the line
		cout << i+1 << "|";
		for(int j=0; j<sizeOfBoard; ++j)
		{
			switch(board[i][j])
			{
			case Board::BLACK:
				cout << " X |";
				break;
			case Board::WHITE:
				cout << " O |";
				break;
			case Board::EMPTY:
				cout << "   |";
				break;
			default:
				break;
			}

		}
		cout << endl;
		// print spaces line
		cout << "----------------------------------" << endl;
	}
}

void ViewByConsole::messageForTurn(Player* curPlayer) const
{
	cout<<curPlayer->strColor()<<": It's your move"<< endl;
}

void ViewByConsole::messagePossibleMoves(vector<Location> &possibleMoves) const
{
	int possibleMovesSize = possibleMoves.size();
	cout<<"Your possible moves: ";
	for (int i=0; i<possibleMovesSize; ++i)
	{
		cout << possibleMoves[i];
		if( i == possibleMovesSize-1)
		{
			cout << endl;
		}
		else
		{
			cout << ",";
		}
	}
	cout<<"Please enter your moves row,col:";
}

virtual Location ViewByConsole::getMoveFromPlayer() const
{
	int row;
	int col;

	//get player's move
	messageEnterMove();
	cin >> row;
	cin >> col;

	// input validation: while the input is not valid - keep asking for valid one
	while(!cin.fail())
	{
		messageInvalidMove();
		cin.clear();
		cin.ignore();
		cin >> row;
		cin >> col;
	}

	return Location(row-1,col-1);
}

void ViewByConsole::messageEnterMove() const
{
	cout<<endl;
	cout<<endl;
	cout<<"Please enter your move row,col:";
}

void ViewByConsole::messageIllegalMove() const
{
	cout<<"Illegal move, please try again! Enter your move row,col: " << endl;
}


void ViewByConsole::messageInvalidMove() const
{
	cout<<"invalid move, please try again! Enter your move row,col: " << endl;
}

void ViewByConsole::messagePlayerMove(Location pointToDisplay, Player* curPlayer)const
{
	cout<<curPlayer->strColor()<<" played "<< pointToDisplay << endl;
}

void ViewByConsole::messageNoMoves() const
{
	cout<<"there are no possible moves for both of the players! Game Over"<<endl;
}

void ViewByConsole::messageSwitchTurns() const
{
	cout<<"No possible moves. Play passes to the other player. press any key to continue."<< endl;
	char anyKey;
	cin >> anyKey;
}

void ViewByConsole::messageBoard() const
{
	cout<<"Current Board:\n"<<endl;
}

void ViewByConsole::messageWinner(Player* winPlayer) const
{
	cout<< winPlayer->strColor()<<" is the WINNER!";
}

void ViewByConsole::messageTiko() const
{
	cout<< "there is no winner - TIKO!";
}
