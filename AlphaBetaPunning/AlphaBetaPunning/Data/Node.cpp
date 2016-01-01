#include "Node.h"
#include <algorithm>

Node::Node(Node* par, size_t coins) : parent(par), value(NO_VALUE), coins(coins), board(coins, true)
{  }

int Node::evaluate(bool max)
{
	return evaluateRec(parent, max);
}

int Node::evaluateRec(Node* current, bool max)
{
	for (auto child : current->children)
	{
		if (current->value == NO_VALUE || (max && child->value > current->value) || (!max && child->value < current->value))
			current->value = child->value;
	}

	if (current->parent == NULL)
		return current->value;

	return evaluateRec(current->parent, !max);
}


void Node::getAvailableMoves(std::vector<Node*>& moves) const
{
	moves.clear();

	size_t take = 3;	
	//boardCopy.sort();

	int m = 0;
	for (int k = 0; k < take; ++k)
	{
		std::vector<bool> boardCopy;
		int* positions = new int[coins];
		int j = 0;
		for (int i = 0; i < board.size(); ++i)
		{
			if (board[i])
				boardCopy.push_back(board[i]);
			else
				positions[j++] = i;
		}

		if (boardCopy.size() > 1)
		{
			for (int i = 0; i < k + 1; ++i)
				boardCopy[i] = false;

		}

		Node* node = NULL;
		do
		{
			for (auto bo : boardCopy)
				printf("%s ", bo ? "1" : "0");
			printf("\n");

			node = new Node(const_cast<Node*>(this), coins);
			node->board = boardCopy;
			moves.push_back(node);
		} while (std::next_permutation(boardCopy.begin(), boardCopy.end()));

		printf("--------\n");

		for (m; m < moves.size(); ++m)
		{
			for (int i = 0; i < j; ++i)
				moves[m]->board.insert(moves[m]->board.begin() + positions[i], false);
			for (auto bo : moves[m]->board)
				printf("%s ", bo ? "1" : "0");
			printf("\n");
		}
		delete positions;
		printf("Next Iteration:\n");
	}
}