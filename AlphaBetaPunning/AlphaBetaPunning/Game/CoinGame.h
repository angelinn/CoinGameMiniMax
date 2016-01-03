#ifndef COIN_GAME_H
#define COIN_GAME_H

class Node;
#include "..\Data\CoinGameResult.h"

class CoinGame
{
public:
	CoinGame(int coins) : coins(coins), top(NULL)
	{  }

	~CoinGame()
	{
		delete top;
	}

public:
	CoinGameResult calculateWinner();

private:
	int minimax(Node *, bool, int, int, int);

private:
	size_t getCoinsToTake(size_t, size_t &) const;
	size_t getCoinIndex() const;

private:
	int coins;
	Node* top;
};


#endif // COIN_GAME_H
