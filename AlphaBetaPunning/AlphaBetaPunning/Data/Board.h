#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board
{
public:
	Board(size_t);
	~Board();

private:
	Board(const Board &) = delete;
	Board& operator=(const Board &) = delete;

public:
	Board* copy() const;
	void take(size_t);
	void generateAvailableMoves(std::vector<Board*> &) const;

private:
	bool* board;
	size_t coins;
};


#endif // BOARD_H
