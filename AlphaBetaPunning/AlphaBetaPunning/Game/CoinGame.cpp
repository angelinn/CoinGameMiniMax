#include "../Data/Node.h"
#include "CoinGame.h"

#define MAX(a, b) a > b ? a : b
#define MIN(a, b) a < b ? a : b

#define INF INT_MAX

CoinGameResult CoinGame::calculateWinner()
{
	top = new Node(NULL, coins);
	CoinGameResult result{ 0, 0, 0 };

	result.moves = minimax(top, true, -INF, INF, 0);
	size_t arrayIndex = getCoinIndex();
	result.count = getCoinsToTake(arrayIndex, result.i);

	return result;
}

size_t CoinGame::getCoinIndex() const
{
	int max = NO_VALUE;
	size_t index = 0;

	for (int i = 0; i < top->children.size(); ++i)
	{
		if (top->children[i]->value > max)
			index = i;
	}

	return index;
}

size_t CoinGame::getCoinsToTake(size_t index, size_t& startCoin) const
{
	size_t count = 0;
	bool gotIt = false;

	for (int i = 0; i < top->children[index]->board.size(); ++i)
	{
		if (!top->children[index]->board[i])
		{
			++count;
			if (!gotIt)
			{
				gotIt = true;
				startCoin = i;
			}
		}
	}

	return count;
}

int CoinGame::minimax(Node* current, bool max, int alpha, int beta, int depth)
{
	int bestValue = max ? -INF : INF;
	int childValue = 0;

	current->getAvailableMoves();
	for (auto& iter : current->children)
	{
		childValue = minimax(iter, !max, alpha, beta, depth + 1);
		bestValue = max ? MAX(bestValue, childValue) : MIN(bestValue, childValue);
		
		if (max)
			alpha = MAX(bestValue, alpha);
		else
			beta = MIN(bestValue, beta);

		if (beta <= alpha)
			break;
	}
	return (current->children.size() == 0) ? current->evaluate(max, depth) : bestValue;
}
