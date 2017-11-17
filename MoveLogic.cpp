/*
 * Yael Hacmon, ID 313597897
 * Roni Fultheim, ID 313465965
 */

#include "MoveLogic.h"
#include <vector>


//empty implementation of c'tor
MoveLogic::MoveLogic() {}

//empty implementation of virtual destructor
MoveLogic::~MoveLogic() {}


bool MoveLogic::canPlayTurn(const Player* player) const {
	//check if player can play moves
	return player->hasPossibleMoves();
}


void MoveLogic::updateMoveOptions(Player* player, const Board* board) const {
	//get board size and initialize variables
	int size = board->size();
	std::vector<Location> final;

	//go over board, for each square check if it can be a move. if so - add to vector.
	for (int r = 0; r < size; r++) {
		for (int c = 0; c< size; c++) {
			//create new location, and add to final vector if it is an allowed move option
			Location curr(r, c);

			//use pure virtual method to decide if a move is allowed (template pattern)
			if (isMoveAllowed(curr, player, board)) {
				final.push_back(curr);
			}
		}
	}

	//update player's list of possible move locations (copies vector using copy c'tor - no error when leaving method)
	player->updatePossibleMoves(final);
}


Location MoveLogic::lastInColorRange(const Color pColor, const Location& prevStart, const Location& end, const Board* board) const {
	/* TARGET: Location of the first square in the given board that matches the given color (not including prevStart).
	 * If none are found - the location of prevStart.
	 * Implementation traverses board by given range, while the location is still in color range.
	 * Requirements for staying in color range:
	 * 1. Location is still in range of board.
	 * 2. Location has the opposite color to given prevStart square. */

	//make sure both prevStart and end are in range of board - if not return prevStart
	if (!board->isInBoardRange(prevStart) || !board->isInBoardRange(end)) {
		return prevStart;
	}

	//find jumps in rows'/columns' numbers using given edge
	int rowJumps = jumps(prevStart.row(), end.row());
	int colJumps = jumps(prevStart.column(), end.column());

	//avoid infinite loop in case both jumps equal zero
	if (rowJumps == 0 && colJumps == 0) {
		return prevStart;
	}

	//initialize current location to start
	Location curr(prevStart);
	curr.increment(rowJumps, colJumps);

	//while current location is still in board range, is not empty, and has the opposite color than prevStart
	while (board->isInBoardRange(curr) && (!board->isSquareEmpty(curr) && !board->compareSquareColors(pColor, curr))) {
		curr.increment(rowJumps, colJumps);
	}

	//if the last square is out of board range, or empty - there is no square matching given color
	if (!board->isInBoardRange(curr) || board->isSquareEmpty(curr)) {
		//return prevStart as required
		return prevStart;
	}

	//return the location before the last - no matter why while loop was broken, the current
	//location is not the wanted one: either not same color or not in range.
	curr.increment(-rowJumps, -colJumps);
	return curr;
}


int MoveLogic::jumps(const int start, const int someNext) const {
	//get difference in rows
	int diff = someNext - start;

	//if difference is positive, then some next is greater than start
	if (diff > 0) {
		//range direction is to the right
		return 1;
	}

	//if difference is negative, then start is greater than some next
	if (diff < 0) {
		//range direction is to the left
		return -1;
	}

	//else - difference is zero - no change in row/column numbers
	return 0;
}
