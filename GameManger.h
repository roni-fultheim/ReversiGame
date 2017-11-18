/*
 * Game.h
 *
 *  313297897
 *  Author: Yael Hacmon
 */

#ifndef GAMEMANGER_H_
#define GAMEMANGER_H_
#include "Board.h"
#include "HumanPlayer.h"
#include "ViewByConsole.h"

// this class is generic for some type of games - manage the steps of the game.

class GameManger
{
public:

	GameManger();
	virtual ~GameManger();

	/**
	 * start and play the game using the virtual functions
	 */
	void play();

	/**
	 * message who is the winner of the game according to the
	 * scors of the player
	 */
	virtual void messageWin() const = 0;

	/**
	 * build vector by possible moves for each player
	 * @param moves vector that represent the possible moves(send with &)
	 */
	virtual void buildVectorByMoves(vector<Point>& moves) const = 0;

	/**
	 * make the final updates of the player step
	 * @param incScores number of the score to increase from the total score
	 * @param decScores number of the score to decrease from the total score
	 */
	virtual void finishSteps(int incScores, int decScores) const = 0;

	/**
	 * update the board according to the player's choice
	 * @param pointToChange the point to change in the board
	 */
	virtual void moveInBoard(Point pointToChange) = 0;

protected:

	Board board_game;
	Player* current_player;
	Player* opp_player;
	ViewGame* view;

};

#endif /* GAMEMANGER_H_ */
