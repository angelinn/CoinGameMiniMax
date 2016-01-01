#include "CoinGame.h"

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define INF INT_MAX

int CoinGame::calculateWinner()
{
	return minimax(top, true);
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
	//bool* state = new bool[coins] { true };
	//top = new Node(NULL, state);


}