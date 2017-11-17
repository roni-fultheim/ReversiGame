/*
 * Yael Hacmon, ID 313597897
 * Roni Fultheim, ID 313465965
 */

#ifndef HUMANCONSOLEPLAYER_H_
#define HUMANCONSOLEPLAYER_H_

#include "Player.h"

/**
 * Represents a human player in a game played via the console.
 */
class HumanConsolePlayer: public Player {
	public:
		/**
		 * Constructor of HumanConsolePlayer. Name and color must be given.
		 *
		 * @param name player's name
		 * @param c player's color
		 */
		HumanConsolePlayer(const std::string& name, const Color& c);

		/**
		 * Gets the player's next move via the console.
		 *
		 * @return Location of player's next move
		 */
		virtual Location getNextMove();
};


#endif /* HUMANCONSOLEPLAYER_H_ */
