/*
 * Roni Fultheim, ID: 313465965
 * Player.h
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include <vector>
#include "Color.h"
#include "Location.h"

/**
 * Repesenting a player in a Reversi game.
 * A player has a name and a color which represents him in the game.
 *
 * Abstract class, as there can be different types of players, which get their next moves in different ways.
 */
class Player {
	public:
		/**
		 * Constructor of Player. Name and color must be given.
		 *
		 * @param name player's name
		 * @param c player's color
		 */
		Player(const std::string& name, const Color& c);

		/**
		 * Virtual destructor.
		 */
		virtual ~Player();

		/**
		 * Returns player's next move in game. Is not constant, since getting next
		 * move can cause player's members to change.
		 *
		 * Pure virtual mbbethod that must be implemented in derived classes,
		 * since getting the next move depends on the player's type.
		 *
		 * @return location of chosen square to make player's color
		 */
		virtual Location getNextMove() = 0;

		/**
		 * Returns the color representing this player in the game.
		 * @return player color in the game
		 */
		Color getColor() const;

		/**
		 * Returns the player's name in the game.
		 *
		 * @return player's name in the game
		 */
		const std::string& getName() const;

		/**
		 * Return's the player's current possible moves, for examination only.
		 * By reference, to avoid copying, constant - to avoid change.
		 *
		 * @return locations where the player could place a square with his color
		 */
		const std::vector<Location>& getPossibleMoves() const;

		/**
		 * Checks if player has possible moves to make.
		 *
		 * @return locations where the player could place a square with his color
		 */
		bool hasPossibleMoves() const;

		/**
		 * Updates the current locations where the player can make his next move to a new vector of possible moves.
		 * Keeping the vector constant ensures that it will be copied.
		 *
		 * @param locs vector of new possible moves
		 */
		void updatePossibleMoves(const std::vector<Location>& locs);

	protected:
		// name of player, cannot be changed during game
		const std::string name_;
		// color of player in the game, cannot be changed during game
		const Color color_;
		//vector of currently possible moves to be made by the player
		std::vector<Location> possibleMoves_;
};


#endif /* PLAYER_H_ */
