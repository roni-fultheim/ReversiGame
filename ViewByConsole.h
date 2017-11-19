/*
 * ViewByConsole.h
 *
 * Yael Hacmon, ID 313597897
 * Roni Fultheim, ID 313465965
 */

#ifndef VIEWBYCONSOLE_H_
#define VIEWBYCONSOLE_H_

#include "ViewGame.h"

class ViewByConsole : public ViewGame
{
public:

	ViewByConsole() {}
	~ViewByConsole() {}
	virtual void printBoard(Board::ElementInBoard** board, int sizeOfBoard) const;
	virtual void messageForTurn(Player* curPlayer) const;
	virtual void messagePossibleMoves(std::vector<Location> &possibleMoves) const;
	virtual Location getMoveFromPlayer() const;
	virtual void messageEnterMove() const;
	virtual void messageInvalidMove() const;
	virtual void messageIllegalMove() const;
	virtual void messagePlayerMove(Location pointToDisplay, Player* curPlayer) const;
	virtual void messageNoMoves() const;
	virtual void messageSwitchTurns() const;
	virtual void messageBoard() const;
	virtual void messageWinner(Player* winPlayer) const;
	virtual void messageTiko() const;
};
#endif /* VIEWBYCONSOLE_H_ */
