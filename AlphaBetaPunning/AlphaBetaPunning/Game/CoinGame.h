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
	void print()
	{
		printf(" %i\n", top->value);
		for (auto child : top->children)
		{
			printf(" %i ", child->value);
		}
		printf("\n");
		for (auto child : top->children)
		{
			for (auto inner : child->children)
			{
				printf(" %i ", inner->value);
			}
		}
		printf("\n");
		for (auto child : top->children)
		{
			for (auto inner : child->children)
			{
				for (auto in : inner->children)
				{
					printf(" %i ", in->value);
				}
			}
		}
		printf("\n");
		for (auto child : top->children)
		{
			for (auto inner : child->children)
			{
				for (auto in : inner->children)
				{
					for (auto hue : in->children)
					{
						printf("%i ", hue->value);
					}
				}
			}
		}
		printf("\n");
	}
	int calculateWinner();

private:
	int minimax(Node *, bool max);
	void generateTree();

private:
	int coins;
	Node* top;
};


#endif // COIN_GAME_H
