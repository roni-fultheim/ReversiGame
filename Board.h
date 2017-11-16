/*
 * Roni Fultheim, ID: 313465965
 *
 * Board.h - header file
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include "Square.h"
#include "Location.h"


/**
 * Represents a Reversi game board.
 * By default board dimentions are 8*8, and game initialization is at center.
 *
 * A board is made of squares, and is only responsible for the organization of the squares as a matrix.
 * It can show that matrix graphically and keeps track of the squares' locations.
 * It does not need to know a square's color and is not responsible for maintaining changes in the square.
 * This allows for loose coupling and high cohesion.
 */
class Board {
	public:
		/**
		 * Default constructor, values are as demanded - 8*8
		 *
		 * @param size size of board
		 */
		Board(int size = 8);

		/**
		 * Destructor, since board size is decided during runtime.
		 */
		~Board();

		/**
		 * Getter for size of board, which equals to number of columns and to number of rows
		 * @return  size of board
		 */
		int size() const;

		/**
		 * Checks if the square in a given location is white.
		 * @param loc square's location
		 * @return true if square is white
		 */
		bool isSquareWhite(const Location& loc) const;

		/**
		 * Checks if the square in a given location is black.
		 * @param loc square's location
		 * @return true if square is black
		 */
		bool isSquareBlack(const Location& loc) const;

		/**
		 * Checks if the square in a given location is empty.
		 * @param loc square's location
		 * @return true if square is empty
		 */
		bool isSquareEmpty(const Location& loc) const;

		/**
		 * Compares a the color of two given squares.
		 * @param loc1 location of square 1
		 * @param loc2 location of square 2
		 * @return true if the square colors are identical, and not empty
		 */
		bool compareSquareColors(const Location& loc1, const Location& loc2) const;

		/**
		 * Compares a the color of a given square to given color.
		 * @param c color to compare square's color to
		 * @param loc location of square
		 * @return true if the colors are identical, and not empty
		 */
		bool compareSquareColors(const Color& c, const Location& loc) const;

		/**
		 * Turns an empty given location to given color.
		 * @param c color to make empty square
		 * @param loc location of square
		 */
		void makeInColor(const Color& c, const Location& loc);

		/**
		 * Changes the color in a given range by given jumps from from black to white and vice versa.
		 *
		 * @param prevStart square before start of range
		 * @param end square of end of range
		 * @param rowJumps jumps with which to iterate on rows
		 * @param colJumps jumps with which to iterate on columns
		 */
		void flipColorInRange(const Location& prevStart, const Location& end, int rowJumps, int colJumps);

		/**
		 * Checks if a given loction is a part of board
		 * @param loc location to check
		 * @return true if location is in range of board
		 */
		bool isInBoardRange(const Location& loc) const;


		/**
		 * Checks if location is at edge of board.
		 * @param loc loaction to check
		 * @return true is location is an edge
		 */
		bool isEdge(const Location& loc) const;

		/**
		 * Overload of << for easy printing to the console.
		 * @param out output stream
		 * @param b board to print
		 * @return output stream with printed square
		 */
		friend std::ostream &operator <<(std::ostream &out, const Board &b);

	private:
		//size of board, cannot be changed after initialization
		const int size_;
		//pointer to matrix of squares representing board, will by dynamically allocated during runtime
		Square** squares_;

		/**
		 * Gets the square at a certain position on the board, for viewing only (square cannot be changed).
		 * This is a wrapping function for clarity of code that ensures safety in terms of changing a square.
		 *
		 * @param loc square's location on board
		 * @return wanted square
		 */
		const Square& getSquare(const Location& loc) const;

		/**
		 * Returns pointer to the square at a certain position on the board by reference.
		 * This is a wrapping function for clarity of code. Board must be able to act on returned square.
		 * Therefore it is returned by reference, not declared 'const' and must be used with care.
		 *
		 * @param loc square's location on board
		 * @return wanted square
		 */
		Square& operateOnSquare(const Location& loc);

		/**
		 * Helper method for printing the board - prints separator line.
		 * @param out output stream to which line should be printed.
		 * @return output stream with line
		 */
		std::ostream& printSeparatorLine(std::ostream &out) const;

		/**
		 * Helper method for printing the board - prints a row.
		 * @param out output stream to which row should be printed.
		 * @return output stream with row
		 */
		std::ostream& printRow(std::ostream &out, int row) const;
};

#endif /* BOARD_H_ */
