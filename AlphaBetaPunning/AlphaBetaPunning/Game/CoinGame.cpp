#include "../Data/Node.h"
#include "CoinGame.h"

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define INF INT_MAX

int CoinGame::calculateWinner()
{
	generateTree();
	return 1;
	//return minimax(top, true, 0);
}

int CoinGame::minimax(Node* current, bool max, int depth)
{
	if (current->children.size() == 0)
	{
		current->value = (coins - depth) * (!max ? 1 : -1);
		return current->value;
	}

	int bestValue = max ? -INF : INF;
	int childValue = 0;

	for (auto iter : current->children)
	{
		childValue = minimax(iter, !max, depth + 1);
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
	printf("val: %d\n", top->value);
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
		printf("val: %d]", child->value);
	}
	printf("\n");
	for (auto child : node->children)
	{
		printRecursive(child);
	}
}