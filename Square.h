/*
 * Roni Fultheim, ID: 313465965
 * Square.h
 */

#ifndef SQUARE_H_
#define SQUARE_H_

#include "Color.h"


/**
 * Represents a square in a Reversi board.
 * A square has a color status: either black, white, or empty
 * It can switch it's status from black to white and vice versa, have a color assigned, and can print itself.
 * It is only responsible for knowing and changing its current state of color.
 */
class Square {
	public:
		Square(Color c = EMPTY);

		/**
		 * Switches color from black to white and vice versa.
		 * Throws exception if square is empty
		 */
		void switchStatus();

		/**
		 * Tells if the square is black.
		 * @return true if the square's color is black
		 */
		bool isBlack() const;

		/**
		 * Tells if the square is white.
		 * @return true if the square's color is white
		 */
		bool isWhite() const;

		/**
		 * Tells if the square is empty.
		 * @return true if the square has no color
		 */
		bool isEmpty() const;

		/**
		 * Assigns square to be black.
		 * Throws exception if square is not empty.
		 */
		void makeBlack();

		/**
		 * Assigns square to be white.
		 * Throws exception if square is not empty.
		 */
		void makeWhite();

		/**
		 * Compares a given square's color to this square's color.
		 * @param s square to compare to
		 * @return true if the square colors are identical, and not empty
		 */
		bool isSameColor(const Square& s) const;

		/**
		 * Compares a given color to this square's color.
		 * @param c color to compare to
		 * @return true if the colors are identical, and not empty
		 */
		bool isSameColor(const Color& c) const;

		/**
		 * Overloading of << for printing easily to console.
		 * @param out output stream
		 * @param s square to print
		 * @return output stream with printed square
		 */
		friend std::ostream &operator <<(std::ostream &out, const Square &s);

	private:
		//status of square: either black, white, or empty.
		Color status_;
};

#endif /* SQUARE_H_ */
