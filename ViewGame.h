/*
 * ViewGame.h
 *
 *  313297897
 *  Author: yael
 */

#ifndef VIEWGAME_H_
#define VIEWGAME_H_
#include "Board.h"
#include "Player.h"

// this cladd represent the view of the game. all the type of the function
// are pure virtual.

class ViewGame
{
public:

	ViewGame() {}
	virtual ~ViewGame() {}
	// present the board
	virtual void printBoard(Board::ElementInBoard** board, int sizeOfBoard) const = 0;

	// message to switch turns
	virtual void messageForTurn (Player* curPlayer) const = 0;

	// message of possible moves
	virtual void messagePossibleMoves(vector<Point> &possibleMoves) const = 0;

	// message for input
	virtual void messageEnterMove() const = 0;

	// massage the move is not valid
	virtual void messageInvalidMove() const = 0;

	// display the player's last move
	virtual void messagePlayerMove(Point pointToDisplay, Player* curPlayer)const = 0;

	// massage that there are no move to do
	virtual void messageNoMoves() const = 0;

	// message to switch turns becouse there are no moves for other player
	virtual void messageSwitchTurns() const = 0;

	// dislpay the board
	virtual void messageBoard() const = 0;

	// message who is the winner
	virtual void messageWinner(Player* winPlayer) const = 0;

	//message if there is "TIKO"
	virtual void messageTiko() const = 0;



};

#endif /* VIEWGAME_H_ */
