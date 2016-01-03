#include "Node.h"
#include "../Permutator/PermutationGenerator.h"

#define MAX_TAKEABLE_COINS 3
#define NO_VALUE -1

Node::Node(Node* par, size_t coins) : parent(par), coins(coins), board(coins, true), value(NO_VALUE)
{  }

Node::~Node()
{
	for (int i = 0; i < children.size(); ++i)
		delete children[i];
}

int Node::evaluate(bool max, int moves)
{
	value = (coins - moves) * (!max ? 1 : -1);
	return value;
}

bool Node::getAvailableMoves()
{
	Permutations permutations;
	bool gotSomething = false;

	for (int i = 0; i < MAX_TAKEABLE_COINS; ++i)
	{
		Node* node = NULL;

		permutations.clear();
		PermutationGenerator::generate(permutations, i + 1, board);
		if (permutations.size())
			gotSomething = true;

		for (auto permutation : permutations)
		{
			node = new Node(const_cast<Node *>(this), coins);
			node->board = permutation;
			children.push_back(node);
		}
	}
	return gotSomething;
}
