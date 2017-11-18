/*
 * GameManger.cpp
 *
 *  313297897
 *  Author: yael Hacmon
 */

#include "GameManger.h"

GameManger::GameManger()
{
	current_player = new HumanPlayer(Board::Black);
	opp_player = new HumanPlayer(Board::White);
	view = new ViewByConsole();
}

GameManger::~GameManger()
{
	delete current_player;
	delete opp_player;
	delete view;
}

// start and play the game using the virtual functions
void GameManger::play()
{
	//noMoves means index to show if for the both of the players
	// there are no moves to do, so the game is over
	bool noMoves = false;
	// build vector of possible moves in the board
	vector <Point> possibleMoves;

	view->messageBoard();
	view->printBoard(board_game.getBoard(), board_game.getSize());

	/* General explanation - First, build a list containing all the
	 * empty cells on the board. then, checking what might be a possible
	 * move dor the player, and putting all the options into a vector.
	 * The user select a point, and the board update acoording to the
	 *  selected point.
	 */

	//while the board is not full
	while(!board_game.isBoardFull())
	{
		//display current turn
		view->messageForTurn(current_player);
		Point p(0,0);
		int index;

		// build the options for the player to move
		buildVectorByMoves(possibleMoves);

		// if the vector of possible moves is not empty
		if(!possibleMoves.empty())
		{
			//display the possible moves for player
			view->messagePossibleMoves(possibleMoves);

			// if the player insert is not a valid input
			while(!current_player->validInput(p))
			{
				view->messageInvalidMove();
			}
			// exit while loop - the player insert point that is valid

			//get the index in the vector which the player choose
			index = current_player->moveByChoice(possibleMoves,p);

			//implement in the type of the game- update the board
			//according to the player's choice
			moveInBoard(possibleMoves[index]);
			//display what was the last move
			view->messagePlayerMove(possibleMoves[index], current_player);
			// turn off the flag of no moves possible
			noMoves = false;

		}
		//if the vector is empty - change turns
		else
		{
			// the second player played in the previous turn
			if(noMoves == false)
			{
				view->messageSwitchTurns();
				noMoves = true;
			}
			//for both of the players- there are no moves
			else
			{
				view->messageNoMoves();
				break;
			}
		}
		// next turn
		index = 0;
		possibleMoves.clear();
		//change the turns - now the curPlayer will be the
		// oppPlayer and the oppPlayer will be the curPlayer
		Player* temp = current_player;
		current_player = opp_player;
		opp_player = temp;

		view->messageBoard();
		view->printBoard(board_game.getBoard(), board_game.getSize());
	}
	messageWin();
}



