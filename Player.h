/*
 * Player.h
 *
 *  313297897
 *  Author: yael
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <vector>
#include "Point.h"
#include "Board.h"
using namespace std;

//Reresent player in the game - his colour and his score

class Player
{
public:

	typedef Board::ElementInBoard ColourOfPlayer;

	Player(ColourOfPlayer colour)
	{
		this->colour = colour;
		score = 2;
	}

	virtual ~Player() {}

	/**
	 *
	 * TODO
	 * return true if the vector is not empty, false otherwise.
	 *
	 */
	virtual bool validInput (Point &point) const =0;

	/**
	 *
	 * TODO
	 * append a vector of possible moves,
	 * retuern the index in the vector which the player choose.
	 *
	 * @param possibleMoves vector of possible moves to the player
	 * @param row choice's player row
	 * @paran col choice's player column
	 */
	virtual int moveByChoice(vector<Point> &possibleMoves, Point &point) const =0;


	/**
	 *
	 * @return colour of player
	 */
	ColourOfPlayer getColor() const
	{
		return colour;
	}

	/**
	 *
	 * @return colour of opposing player
	 */
	ColourOfPlayer getOppColor() const
	{
		if (colour == Board::Black)
		{
			return Board::White;
		}
		return Board::Black;
	}

	/**
	 * @return the player's name
	 */
	char strColor() const
	{
		if (colour == Board::Black)
		{
			return 'X';
		}
		return 'O';
	}

	/**
	 * @return the player's score
	 */
	int gerScore()const
	{
		return score;
	}

	// if curPlayer "eat" the oppPlayer- the oppPlayer score decreases
	void decreaseScore (int toDecrease)
	{
		score = score - toDecrease;
	}
	// if curPlayer "eat" the oppPlayer- he curPlayer score increases
	void increaseScore (int toIncrease)
	{
		score = score + toIncrease;
	}

protected:

	ColourOfPlayer colour;
	int score;

};

#endif /* PLAYER_H_ */
