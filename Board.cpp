/*
 * Roni Fultheim, ID: 313465965
 *
 * Board.cpp - implementation file
 */

//includes for IO functions, use of vectors, and use of exit function
#include <iostream>
#include <cstdlib>
#include <stdexcept>

//include header file
#include "Board.h"

using namespace std;


Board::Board(int size): size_(size) {
	//allocate array of pointers of squares to represent board's first column (size_= #of rows)
	// wrapped in try-catch block as expected
	try {
		squares_ = new Square*[size_];
	} catch (...) {
		cout << "Allocation of board failed: EXITING GAME" << endl;
		exit(0);
	}

	//allocate all rows (size_= #of columns), and initialize matrix with empty squares
	for (int i = 0 ; i<size_; i++) {
		// allocate rows
		// wrapped in try-catch block as expected
		try {
			squares_[i] = new Square[size_];
		} catch (...) {
			cout << "Allocation of board failed: EXITING GAME" << endl;
			exit(0);
		}

		// initialize empty squares
		for (int j = 0 ; j< size_; j++) {
			//square will be empty by default
			squares_[i][j] = Square();
		}
	}

	//initialize board for game - white is always at upper left corner of initialization square
	//notice that c++ indexing requires to divide size in 2 then subtract 1 to reach the center of board
	//initialize white squares
	Location loc(size/2-1, size/2-1);
	operateOnSquare(loc).makeWhite();
	loc.set(size/2, size/2);
	operateOnSquare(loc).makeWhite();
	//initialize black squares
	loc.set(size/2-1, size/2);
	operateOnSquare(loc).makeBlack();
	loc.set(size/2, size/2-1);
	operateOnSquare(loc).makeBlack();
}


Board::~Board() {
	//delete rows of matrix
	for (int i = 0; i<size_; i++) {
		delete squares_[i];
	}
	//delete first column
	delete squares_;
}


int Board::size() const {
	return size_;
}


bool Board::isSquareWhite(const Location& loc) const {
	Square s = getSquare(loc);
	return s.isWhite();
}


bool Board::isSquareBlack(const Location& loc) const {
	Square s = getSquare(loc);
	return s.isBlack();
}


bool Board::isSquareEmpty(const Location& loc) const {
	Square s = getSquare(loc);
	return s.isEmpty();
}


bool Board::compareSquareColors(const Location& loc1, const Location& loc2) const {
	Square s1 = getSquare(loc1);
	Square s2 = getSquare(loc2);
	return s1.isSameColor(s2);
}


void Board::makeInColor(const Color& c, const Location& loc) {
	switch (c) {
		case WHITE:
			operateOnSquare(loc).makeWhite();
			break;
		case BLACK:
			operateOnSquare(loc).makeBlack();
			break;
		default:
			cout << "Problem: given color is not recognized - color must be black or white." << endl;
			break;
	}
}


bool Board::compareSquareColors(const Color& c, const Location& loc) const {
	return getSquare(loc).isSameColor(c);
}


void Board::flipColorInRange(const Location& prevStart, const Location& end, int rowJumps, int colJumps) {
	//make sure both prevStart and end are in range of board
	if (!isInBoardRange(prevStart) || !isInBoardRange(end)) {
		return;
	}

	//avoid infinite loop in case of no jumps
	if (rowJumps == 0 && colJumps == 0) {
		return;
	}

	//iterate over board and change the location:
	//initialize start of range
	Location curr(prevStart);

	//if end location cannot be reached by given jumps - there is no way to know when to stop
	//check if row/column jumps are 0 before using the % operation (undefined for 0)
	if (((rowJumps != 0) && ((end.row()-curr.row()) % rowJumps != 0)) ||
			((colJumps) != 0 &&  ((end.column()-curr.column()) % colJumps != 0))) {
		//return to avoid infinite loop
		return;
	}

	//while location is still in given range - has not yet reached end
	while (curr != end) {
		//first move to next square (started with square previous to start)
		curr.increment(rowJumps, colJumps);
		//then flip next square
		operateOnSquare(curr).switchStatus();
	}
}


bool Board::isInBoardRange(const Location& loc) const {
	//check that row and column values are between 0 and board size-1
	return (loc.row() >= 0 && loc.column() >= 0 && loc.row() < size_ && loc.column() < size_);
}


bool Board::isEdge(const Location& loc) const {
	return (loc.row()==0 || loc.row()==(size_-1) || loc.column()==0 || loc.column()==(size_-1));
}


std::ostream &operator <<(std::ostream &out, const Board &b) {
	// print column numbering (top row)
	for (int i = 0; i < b.size_; i++) {
		//print all numbers by given format
		out << " | " << i+1;
	}
	//add last pipe and end line
	out << " |" << endl;
	//print first separator line
	b.printSeparatorLine(out);

	//print board by iterating over rows
	for (int i = 0; i< b.size_; i++) {
		//print row number
		out << i+1;
		//print rows
		b.printRow(out, i);
		//print separator line
		b.printSeparatorLine(out);
	}

	return out;
}


const Square& Board::getSquare(const Location& loc) const {
	// check that square is in range of board, throw exception if not
	if (!isInBoardRange(loc)) {
		throw out_of_range("Problem: tried to get a square out of board range\t");
	}

	//returned constant, so that square cannot be changed
	return squares_[loc.row()][loc.column()];
}


Square& Board::operateOnSquare(const Location& loc) {
	// check that square is in range of board, throw exception if not
	if (!isInBoardRange(loc)) {
		throw out_of_range("Problem: tried to operate on a square out of board range\n");
	}
	//returned by reference, so that square can be acted upon
	return squares_[loc.row()][loc.column()];
}


std::ostream& Board::printSeparatorLine(std::ostream &out) const {
	// print '-' as many times as needed, according to board size
	// taking row numbering into consideration
	// 4 '-' per a '|    ', plus one under the row number and under the last '|'
	for (int i=0; i< size_*4+2 ; i++) {
		out << "-";
	}
	//end row
	out << endl;

	return out;
}


std::ostream& Board::printRow(std::ostream &out, int row) const {
	// print '| ' then SQUARE ('  ' / 'X' / 'O') then another ' '
	Location loc(0,0);
	for (int i=0; i<size_; i++) {
		out << "| ";
		loc.set(row, i);
		//getSquare(loc).print();
		out << getSquare(loc) << " ";
	}
	// print the last '|' and then end line.
	out << "|" << endl;

	return out;
}
