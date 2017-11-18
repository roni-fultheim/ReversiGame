/*
 * Board.cpp
 *
 *  313297897
 *  Author: yael Hacmon
 */

#include "Board.h"
using namespace std;

int Board::default_board_size = 8;

Board::Board(int size):size_of_board(size)
{
	game_board = new ElementInBoard*[size_of_board];

	for(int i = 0; i < size_of_board; ++i)
	{
		game_board[i] = new ElementInBoard[size_of_board];
	}

	// init the content of the board to be empty
	for(int i=0; i<size_of_board ;++i)
	{
		for(int j=0; j<size_of_board; ++j)
		{
			game_board[i][j] = Empty;
			empty_cells.push_back(Point(i,j));
		}
	}
	// set the first elements of the players
	game_board[size_of_board/2][size_of_board/2]= White;
	empty_cells.remove(Point((size_of_board/2),(size_of_board/2)));

	game_board[size_of_board/2 -1][size_of_board/2 -1]= White;
	empty_cells.remove(Point((size_of_board/2 -1),(size_of_board/2 -1)));

	game_board[size_of_board/2][size_of_board/2 -1]= Black;
	empty_cells.remove(Point((size_of_board/2),(size_of_board/2 - 1)));

	game_board[size_of_board/2 -1][size_of_board/2]= Black;
	empty_cells.remove(Point((size_of_board/2 - 1),(size_of_board/2)));

}

Board::~Board()
{
	for(int i=0; i<size_of_board; ++i)
	{
		delete [] game_board[i];
	}
	delete[] game_board;
}

int Board::getSize() const
{
	return size_of_board;
}

Board::ElementInBoard** Board::getBoard() const
{
	return game_board;
}

Board::ElementInBoard Board::getElementInBoard(int row, int col) const
{
	return game_board[row][col];
}

void Board::setElementInBoard(Board::ElementInBoard colour, int row, int col)
{
	game_board[row][col] = colour;
}

list<Point>::const_iterator Board::emptyCellsBegin() const
{
	return empty_cells.begin();
}

list<Point>::const_iterator Board::emptyCellsEnd() const
{
	return empty_cells.end();
}

bool Board::isBoardFull() const
{
	return empty_cells.empty();
}

void Board::romoveCellFromEmptyList(Point removalPoint)
{
	empty_cells.remove(removalPoint);
}
