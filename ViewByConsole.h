/*
 * ViewByConsole.h
 *
 *  313297897
 *  Author: yael
 */

#ifndef VIEWBYCONSOLE_H_
#define VIEWBYCONSOLE_H_

#include "ViewGame.h"
#include "Board.h"
#include "ViewByConsole.h"

class ViewByConsole : public ViewGame
{
public:

	ViewByConsole() {}
	~ViewByConsole() {}
	virtual void printBoard(Board::ElementInBoard** board, int sizeOfBoard) const;
	virtual void messageForTurn(Player* curPlayer) const;
	virtual void messagePossibleMoves(vector<Point> &possibleMoves) const;
	virtual void messageEnterMove() const;
	virtual void messageInvalidMove() const;
	virtual void messagePlayerMove(Point pointToDisplay, Player* curPlayer) const;
	virtual void messageNoMoves() const;
	virtual void messageSwitchTurns() const;
	virtual void messageBoard() const;
	virtual void messageWinner(Player* winPlayer) const;
	virtual void messageTiko() const;
};
#endif /* VIEWBYCONSOLE_H_ */
