/*
 * Roni Fultheim, ID: 313465965
 * Square.cpp
 */
#include <iostream>
#include <stdexcept>
#include "Square.h"

using namespace std;


Square::Square(Color c): status_(c) {}


void Square::switchStatus() {
	//using switch case to switch color from black to white and vice versa
	switch(status_) {
		case BLACK:
			status_ = WHITE;
			break;
		case WHITE:
			status_ = BLACK;
			break;
		default:
			// if square color is empty or unassigned, there is a problem
			throw logic_error("Logic problem: tried switching an empty square's color\n");
	}
}


bool Square::isBlack() const {
	//compare, return value of comparison
	return (status_ == BLACK);
}


bool Square::isWhite() const {
	//compare, return value of comparison
	return (status_ == WHITE);
}


bool Square::isEmpty() const {
	//compare, return value of comparison
	return (status_ == EMPTY);
}


void Square::makeBlack() {
	//check that the square isn't colored yet and change color
	if (status_ == EMPTY) {
		status_ = BLACK;
	} else {
		// if function is invoked while square is not empty, there is a logical problem in the code
		throw logic_error("Logic problem: tried to make a non-empty square black.\n");
	}
}


void Square::makeWhite() {
	//check that the square isn't colored yet and change color
	if (status_ == EMPTY) {
		status_ = WHITE;
	} else {
		// if function is invoked while square is not empty, there is a logical problem in the code
		throw logic_error("Logic problem: tried to make a non-empty square white.\n");
	}
}

bool Square::isSameColor(const Square &s) const {
	switch (status_) {
		//return true if squares' colors match, false otherwise
		case BLACK:
			if (s.isBlack()) {
				return true;
			}
			return false;
		case WHITE:
			if (s.isWhite()) {
				return true;
			}
			return false;
		//an empty square has no color to be comared to
		case EMPTY:
			return false;
		default:
			//if this square has no color - this is a problem
			cout << "problem comparing color of squares" << endl;
			break;
		//in case of default
		return false;
	}
}


bool Square::isSameColor(const Color& c) const {
	switch (c) {
		//return true if squares' colors match, false otherwise
		case BLACK:
			if (isBlack()) {
				return true;
			}
			return false;
		case WHITE:
			if (isWhite()) {
				return true;
			}
			return false;
		//an empty square has no color to be comared to
		case EMPTY:
			return false;
		default:
			//if this square has no color - this is a problem
			cout << "problem comparing color of squares" << endl;
			break;
		//in case of default
		return false;
	}
}


std::ostream &operator <<(std::ostream &out, const Square &s) {
	//switch case of square's color
	switch(s.status_) {
		case EMPTY:
			out << " ";
			break;
		case BLACK:
			out << "X";
			break;
		case WHITE:
			out << "O";
			break;
		default:
			// if square color is empty or unassigned, there is a problem - print directly to console
			cout << endl << "square is of unrecognized color: cannot print" << endl;
			break;
	}

	 return out;
}
