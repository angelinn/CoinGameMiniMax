#include <stdio.h>
#include <algorithm>
#include <vector>
#include "Game/CoinGame.h"

int main(int argc, const char* argv[])
{
	int coinCount = 5; // argv[1];

	try
	{
		//std::vector<bool> a{ true, true, true, true, true };
		//Node node(NULL, a.size());
		//node.board = a;
		//std::vector<Node*> results;
		//node.getAvailableMoves(results);

		CoinGame game(coinCount);
		game.calculateWinner();
	}
	catch (std::exception e)
	{
		printf("%s\n", e.what());
	}

	_CrtDumpMemoryLeaks();
	return 0;
}