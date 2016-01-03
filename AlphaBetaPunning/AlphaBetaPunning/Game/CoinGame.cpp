#include "../Data/Node.h"
#include "CoinGame.h"

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define INF INT_MAX

int CoinGame::calculateWinner()
{
	generateTree();
	return minimax(top, true, -INF, INF, 0);
}

int CoinGame::minimax(Node* current, bool max, int alpha, int beta, int depth)
{
	if (current->children.size() == 0)
		return current->evaluate(max, depth);

	int bestValue = max ? -INF : INF;
	int childValue = 0;

	for (auto iter : current->children)
	{
		childValue = minimax(iter, !max, alpha, beta, depth + 1);
		bestValue = max ? MAX(bestValue, childValue) : MIN(bestValue, childValue);
		
		if (max)
			alpha = MAX(bestValue, alpha);
		else
			beta = MIN(bestValue, beta);

		if (beta <= alpha)
		{
			printf("BREAKING..\n");
			break;
		}
	}
	return bestValue;
}

void CoinGame::generateTree()
{
	top = new Node(NULL, coins);
	generateTreeRecursive(top);
}

void CoinGame::generateTreeRecursive(Node* parent)
{
	std::vector<Node*> nextGeneration;
	if (!parent->getAvailableMoves(nextGeneration))
		return;

	for (auto& node : nextGeneration)
	{
		node->parent = parent;
		parent->children.push_back(node);
	}

	for (auto& node : parent->children)
		generateTreeRecursive(node);
}

void CoinGame::print() const
{
	for (bool cur : top->board)
		printf("%d ", cur);
	printRecursive(top);
}

void CoinGame::printRecursive(const Node* node) const
{	
	if (node->children.size() == 0)
		return;

	for (auto child : node->children)
	{
		printf("[");
		for (bool cur : child->board)
			printf("%d ", cur);
	}
	printf("\n");
	for (auto child : node->children)
	{
		printRecursive(child);
	}
}