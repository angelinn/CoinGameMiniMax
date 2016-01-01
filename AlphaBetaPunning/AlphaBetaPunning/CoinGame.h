#ifndef COIN_GAME_H
#define COIN_GAME_H

#include "Node.h"
#include <stdio.h>

class CoinGame
{
public:
	CoinGame()
	{
		top = new Node(NULL);
		top->children.push_back(new Node(top));
		top->children.push_back(new Node(top));

		for (auto child : top->children)
		{
			child->children.push_back(new Node(child));
			child->children.push_back(new Node(child));

			for (auto inner : child->children)
			{
				inner->children.push_back(new Node(inner));
				inner->children.push_back(new Node(inner));
				for (auto in : inner->children)
				{
					Node* node = new Node(in);
					node->value = rand() % 20;
					in->children.push_back(node);
					node = new Node(in);
					node->value = rand() % 20;
					in->children.push_back(node);
				}
			}
		}
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

private:
	Node* top;
};


#endif // COIN_GAME_H
