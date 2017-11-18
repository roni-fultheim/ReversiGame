/*
 * HumanPlayer.h
 *
 *  313297898
 *  Author: yael Hacmon
 */

#ifndef HUMANPLAYER_H_
#define HUMANPLAYER_H_
#include "Player.h"

//Represent a console player

class HumanPlayer : public Player
{
public:
	HumanPlayer(ColourOfPlayer color);

	virtual ~HumanPlayer() {}

	virtual bool HumanPlayer::validInput (Point &point);

	virtual int HumanPlayer::moveByChoice(vector<Point> &possibleMoves,Point &point);

};

#endif /* HUMANPLAYER_H_ */
