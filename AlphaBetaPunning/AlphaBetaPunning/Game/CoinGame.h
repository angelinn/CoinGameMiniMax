#ifndef COIN_GAME_H
#define COIN_GAME_H

class Node;

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
	void print() const;
	int calculateWinner();

private:
	int minimax(Node *, bool, int, int, int);
	void generateTree();

	void generateTreeRecursive(Node *);
	void printRecursive(const Node *) const;

private:
	int coins;
	Node* top;
};


#endif // COIN_GAME_H
