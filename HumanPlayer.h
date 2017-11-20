/*
 * Roni Fultheim, ID: 313465965
 * HumanPlayer.h
 */

#ifndef HumanPlayer_H_
#define HumanPlayer_H_

#include "Player.h"


/**
 * Represents a human player in a game played via the console.
 */
class HumanPlayer: public Player {
public:

	HumanPlayer(const std::string& name, const Player::ColorOfPlayer& c): Player(name, c){};


	/**
	 * Returns player's next move in game by asking user to enter their choice.
	 *
	 * @param v view to interact with player - accept input and make sure input is valid
	 * @param logic rules of current game
	 * @param b board on which game is being played
	 * @param other opponent
	 * @return location of next player's move
	 */
	Location getNextMove(ViewGame* view, MoveLogic* logic, Board* board, Player* other); //TODO YAEL - view needed?
};


#endif /* HumanPlayer_H_ */
