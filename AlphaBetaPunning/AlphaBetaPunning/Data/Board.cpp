#include "Board.h"

#include <stdexcept>
#include <algorithm>
#include <vector>

Board::Board(size_t coinCount) : board(NULL), coins(coinCount)
{
	board = new bool[coins] { true };
}

Board::~Board()
{
	delete board;
}

Board* Board::copy() const
{
	Board* copy = new Board(coins);
	for (int i = 0; i < coins; ++i)
		copy->board[i] = board[i];

	return copy;
}

void Board::take(size_t position)
{
	if (position < 0 || position > coins - 1)
		throw std::out_of_range("position out of range at line: " + __LINE__);

	board[position] = false;
}

void Board::generateAvailableMoves(std::vector<Board*>& moves) const
{
	moves.clear();

	int take = 0;
	do
	{
		Board* wohoo = new Board(coins);
		wohoo->take(take++);
	} while (true);
}