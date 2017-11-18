/*
 * Board.h
 *
 *  313297897
 *  Author: yael Hacmon
 */

#ifndef BOARD_H_
#define BOARD_H_
#include "Point.h"
#include <list>
using namespace std;

class Board
{
	//default size of board, if there is no input
	static int default_board_size;

public:

	enum ElementInBoard {Black, White, Empty}; // black- 'X". white-'O'

	Board(int size = default_board_size);
	~Board();

	/**
	 * @return size of board
	 */
	int getSize() const;

	/**
	 * @return board
 	 */
	Board::ElementInBoard** getBoard() const;

	/**
	 * @param row element row
	 * @param col element co column
	 * @return element in board in board [row,col] - White,Black or Empty
	 */
	Board::ElementInBoard getElementInBoard(int row, int col) const;

	/**
	 * update the element in board to be the type of the colour
	 *
	 * @param colour colour to uptade
	 * @param row element row
	 * @param col element column
	 */
	void setElementInBoard(Board::ElementInBoard colour, int row, int col);

	/**
	 * check if there is no empty cells by checking if
	 * the board is full
	 *
	 * @return True if there are no empty cells, False otherwise
	 */
	bool isBoardFull() const;

	/**
	 * @return iterator to the begin of the empty cells list
	 */
	list<Point>::const_iterator emptyCellsBegin() const;

	/**
	 * @return iterator to the end of the empty cells list
	 */
	list<Point>::const_iterator emptyCellsEnd() const;

	/**
	 * remove point from the list
	 *
	 * @param removalPoint point for removal
	 */
	void romoveCellFromEmptyList(Point removalPoint);

private:

	const int size_of_board;
	ElementInBoard ** game_board;
	//list points of empty cells in board
	list<Point> empty_cells;

};
#endif /* BOARD_H_ */
