#include "CoinGame.h"
#include <deque>

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define INF INT_MAX

int CoinGame::calculateWinner()
{
	generateTree();
	return 1;
	//return minimax(top, true);
}

int CoinGame::minimax(Node* current, bool max)
{
	if (current->children.size() == 0)
		return current->evaluate(max);

	int bestValue = max ? INF : -INF;
	int childValue = 0;

	for (auto iter : current->children)
	{
		childValue = minimax(iter, !max);
		bestValue = max ? MAX(bestValue, childValue) : MIN(bestValue, childValue);
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

	for (auto node : nextGeneration)
	{
		node->parent = parent;
		parent->children.push_back(node);
		generateTreeRecursive(node);
	}
}

void CoinGame::print() const
{
	for (bool cur : top->board)
		printf("%d ", cur);
	printf("\n");
	printRecursive(top);
}

int z = 0;

void CoinGame::printRecursive(const Node* node) const
{	
	if (node->children.size() == 0)
	{
		return;
	}



	int current = z;
	for (auto child : node->children)
	{
		printf("[");
		for (bool cur : child->board)
			printf("%d ", cur);
		printf("]");
	}
	printf("\n");
	for (auto child : node->children)
	{
		printRecursive(child);
	}
}