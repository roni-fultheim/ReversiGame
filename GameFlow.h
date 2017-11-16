/*
 * Roni Fultheim, ID: 313465965
 * GameFlow.h
 */

#ifndef GAMEFLOW_H_
#define GAMEFLOW_H_

#include <iostream>
#include "Board.h"
#include "MoveLogic.h"
#include "Player.h"
#include "Location.h"

/**
 * Controls the game flow of a Reversi game when given a board, two players
 * and an object to control the logic of every move.
 *
 * Is responsible for playing the turns, knowing and notifying when the game ends, and printing
 * messages to the players.
 */
class GameFlow {
public:
	/**
	 * Constructor taking a board on which to play game, two players, and the logic of the moves.
	 * @param b board of game
	 * @param black black player
	 * @param white white player
	 * @param log logic to handle moves
	 */
	GameFlow(Board* b, Player* black, Player* white, MoveLogic* log);

	/**
	 * Plays game with the given board, players and logic.
	 */
	void playGame();

private:
	//board of game
	Board* board_;

	//black player - by reference, to allow polymorphism
	Player* black_;

	//white player - by reference, to allow polymorphism
	Player* white_;

	//handles logic of moves - by reference, to allow polymorphism
	MoveLogic* logic_;

	//location of last played move - must be allocated in
	Location lastMove_;

	/**
	 * Plays turn of a given player. Method for clarity and code reuse.
	 * Is not constant, since playing a turn can cause either player's to change.
	 *
	 * @param playing player currently playing
	 * @param other other player
	 * @return true if player has played this turn
	 */
	bool playTurn(Player* playing, Player* other);

	/**
	 * Returns winner of game.
	 * @return player who won this game
	 */
	void showWinner();
};


#endif /* GAMEFLOW_H_ */
