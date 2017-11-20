/*
 * Roni Fultheim, ID: 313465965
 * GameManager.cpp
 */

#include "GameManager.h"
#include <iostream>

using namespace std;

GameManager::GameManager(ViewGame* view, Board* b, Player* black, Player* white, MoveLogic* log):
										board_(b), currPlayer_(black), oppPlayer_(white), logic_(log), view_(view) {}


void GameManager::playGame() {
	//declare flag - in first turn game has not been played, current player has moves
	bool noMoves = false;

	view_->messageBoard();
	view_->printBoard(board_->getBoard(), board_->size());

	/* General explanation - First, build a list containing all the
	 * empty cells on the board. then, checking what might be a possible
	 * move dor the player, and putting all the options into a vector.
	 * The user select a point, and the board update acoording to the
	 *  selected point.
	 */

	//while game is not over - keep playing
	while (!board_->isBoardFull())
	{
		//display current turn
		view_->messageForTurn(currPlayer_);

		//initialize moves for black and white players
		logic_->updateMoveOptions(currPlayer_, board_);

		//if current player can play his turn
		if (logic_->canPlayTurn(currPlayer_)) {
			//show possible moves
			view_->messagePossibleMoves(currPlayer_->getPossibleMoves());

			//get next player's move
			Location move = currPlayer_->getNextMove(view_, logic_, board_, oppPlayer_);

			//check that move is allowed
			//while move isn't legal - get another move from player
			while (!logic_->isMoveAllowed(move, currPlayer_, board_))
			{
				view_->messageIllegalMove();
				move = currPlayer_->getNextMove(view_, logic_, board_, oppPlayer_);
			}

			//call logic to play move
			logic_->playMove(move, currPlayer_, board_);

			//message of last turn
			view_->messagePlayerMove(move, currPlayer_);

			//update flag
			noMoves = false;
		}
		//if current player cannot play his turn
		else
		{
			//if the second player cannot play - show message and switch turns
			if (!noMoves) {
				view_->messageSwitchTurns();
				noMoves = true;

			}
			else
			{
				//if both players did not play - game is over, there are no more moves left in game
				view_->messageNoMoves();
				break;
			}
		}

		//switch players
		Player* temp = currPlayer_;
		currPlayer_ = oppPlayer_;
		oppPlayer_ = temp;

		//show board and last moves
		view_->messageBoard();
		view_->printBoard(board_->getBoard(), board_->size());
	}
	showWinner();
}


bool GameManager::playTurn(Player* playing, Player* other) {
	//if the playing player cannot play - notify, update and return false
	if (!logic_->canPlayTurn(playing)) {
		//print message and newline, using cin methods to implement waiting for enter
		//(cin>>variable does not work - must press enter in addition)
		cout << "No possible moves. Play passes back to the other player. Press ENTER to continue... ";
		cin.ignore();
		cin.get();
		cout << endl;

		//update other player's move - changed from his last turn
		logic_->updateMoveOptions(other, board_);

		//and return false (mark that player didn't play)
		return false;
	}


	//otherwise, print possible moves
	cout << "Your possible moves: ";
	//get moves and declare constant iterator
	vector<Location>::const_iterator i;
	vector<Location> moves = playing->getPossibleMoves();
	//iterate over given moves and print them
	for(i=moves.begin(); i != moves.end()-1; ++i){
		//print location
		cout << (*i) << " , ";
	}
	//print last location
	cout << (*(moves.end()-1)) << endl;

	//get player's choice of move
	Location move = playing->getNextMove(view_, logic_, board_, other);

	//while move isn't legal - get another move from player
	while (!logic_->isMoveAllowed(move, playing, board_))
	{
		view_->messageIllegalMove();
		move = playing->getNextMove(view_, logic_, board_, other);
	}

	//call logic to play move
	logic_->playMove(move, playing, board_);
	//update other player's options after playing move
	logic_->updateMoveOptions(other, board_);

	// TODO : YAEL - ask Roni
	//save location of last move made in game
	//lastMove_.set(move);

	//mark that player has played
	return true;
}


void GameManager::showWinner()
{
	if (currPlayer_->getScore() > oppPlayer_->getScore()) {
		view_->messageWinner(currPlayer_);
	}
	else if (currPlayer_->getScore() < oppPlayer_->getScore())
	{
		view_->messageWinner(oppPlayer_);
	}
	else
	{
		view_->messageTiko();
	}
}
