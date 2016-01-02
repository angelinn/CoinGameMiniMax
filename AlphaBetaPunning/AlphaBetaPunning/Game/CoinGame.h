#ifndef COIN_GAME_H
#define COIN_GAME_H

#include "..\Data\Node.h"
#include <stdio.h>

class CoinGame
{
public:
	CoinGame(int coins) : coins(coins)
	{

	}

public:
	void print() const;
	int calculateWinner();

private:
	int minimax(Node *, bool max);
	void generateTree();

	void generateTreeRecursive(Node *);
	void printRecursive(const Node *) const;

private:
	int coins;
	Node* top;
};


#endif // COIN_GAME_H
