/*
 * Roni Fultheim, ID: 313465965
 * GameFlow.cpp
 */

#include "GameFlow.h"
#include <iostream>

using namespace std;

GameFlow::GameFlow(Board* b, Player* black, Player* white, MoveLogic* log):
		board_(b), black_(black), white_(white), logic_(log), lastMove_(-1,-1) {}


void GameFlow::playGame() {
	//initialize moves for black and white players
	logic_->updateMoveOptions(black_, board_);
	logic_->updateMoveOptions(white_, board_);

	//declare flags - in first turn game has not been playedno turn has been played
	bool blackPlayed = false;
	bool whitePlayed = false;
	//initialize counter of made turns with maximal number of turns possible (size of board squared, minus the 4 initialized tiles)
	int steps = (board_->size()*board_->size())-4;


	//while game is not over - keep playing
	while (true) {
		//BLACK TURN FIRST
		//print current game board
		cout << endl << "Current board:"  << endl << *board_;

		//if a move has been played by white - show last move
		if (whitePlayed) {
			cout << white_->getName() << " played " << lastMove_ << endl;
			steps--;
		}

		//if board is full - game is over
		if (steps == 0) {
			break;
		}

		//notify who's turn it is and play turn
		cout << endl <<  black_->getName() << ": It's your move." << endl;
		blackPlayed = playTurn(black_, white_);

		//if black did not play, and white has no possible moves to make - game is over
		if (!blackPlayed && !white_->hasPossibleMoves()) {
			break;
		}

		//THEN WHITE TURN
		//print current game board and play white turn
		cout << endl << "Current board:"  << endl << *board_;
		//if a move has been played by black - show last move
		if (blackPlayed) {
			cout << black_->getName() << " played " << lastMove_ << endl;
			steps--;
		}

		//if board is full - game is over
		if (steps == 0) {
			break;
		}

		//notify who's turn it is and play turn
		cout << endl << white_->getName() << ": It's your move." << endl;
		whitePlayed = playTurn(white_, black_);

		//if white did not play, and black has no possible moves to make - game is over
		if (!whitePlayed && !black_->hasPossibleMoves()) {
			break;
		}
	}

	//game is over - declare winner
	showWinner();
}


bool GameFlow::playTurn(Player* playing, Player* other) {
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
	Location move = playing->getNextMove();

	//while move isn't legal - get another move from player
	while (!logic_->isMoveAllowed(move, playing, board_)) {
		std::cout << "Illegal move. ";
		move = playing->getNextMove();
	}

	//call logic to play move
	logic_->playMove(move, playing, board_);
	//update other player's options after playing move
	logic_->updateMoveOptions(other, board_);

	//save location of last move made in game
	lastMove_.set(move);

	//mark that player has played
	return true;
}


void GameFlow::showWinner() {
	//get number of white and black squares from board
	int whites = 0, blacks = 0;
	Location curr(0,0);

	//go over board and count number of squares from each color
	for (int i = 0; i< board_->size(); i++) {
		for (int j = 0; j < board_->size(); j++) {
			curr.set(i, j);
			//if square is white - increment counter
			if (board_->isSquareWhite(curr)) {
				whites++;
			//else if square is black - increment counter
			} else if (board_->isSquareBlack(curr)) {
				blacks++;
			}
			//if square is empty - do nothing
		}
	}

	//notify of end of game
	cout << endl << "GAME OVER! No more moves can be made this game." << endl;

	//print results
	cout << black_->getName() << ": " << blacks << " points, " << white_->getName() << ": " << whites << " points" << endl;

	//find who the winner is
	//in case of a tie
	if (blacks == whites) {
		cout << "TIE! Both players have " << whites << " points." << endl;
	} else if (blacks > whites) {
		//else if black wins
		cout << "Congratulations " << black_->getName() << "! You have won the game :)" << endl;
	} else {
		//else - white won
		cout << "Congratulations " << white_->getName() << "! You have won the game :)" << endl;
	}
}
