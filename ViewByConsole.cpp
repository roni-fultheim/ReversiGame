/*
 * ViewByConsole.cpp
 *
 *  313297897
 *  Author: yael
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
			case Board::Black:
				cout << " X |";
				break;
			case Board::White:
				cout << " O |";
				break;
			case Board::Empty:
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

void ViewByConsole::messagePossibleMoves(vector<Point> &possibleMoves) const
{
	int possibleMovesSize = possibleMoves.size();
	cout<<"Your possible moves: ";
	for (int i=0; i<possibleMovesSize; ++i)
	{
		int x = possibleMoves[i].getX() + 1;
		int y = possibleMoves [i].getY() + 1;
		cout << "(" << x << "," << y << ")";
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

void ViewByConsole::messageEnterMove() const
{
	cout<<endl;
	cout<<endl;
	cout<<"Please enter your move row,col:";
}

void ViewByConsole::messageInvalidMove() const
{
	cout<<"invalid move- please try again!" << endl;
}

void ViewByConsole::messagePlayerMove(Point pointToDisplay, Player* curPlayer)const
{
	int x = pointToDisplay.getX() +1;
	int y = pointToDisplay.getY() +1;
	cout<<curPlayer->strColor()<<" played"<< " ("<< x << ","<< y << ")\n" << endl;
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
