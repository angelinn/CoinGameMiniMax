#include <stdio.h>
#include <vector>
#include "Permutator\PermutationGenerator.h"
#include "Game\CoinGame.h"
#include "Data\Node.h"

int main(int argc, const char* argv[])
{
	int coinCount = 8; // argv[1];

	try
	{
		CoinGame game(coinCount);
		int result = game.calculateWinner();
		//game.print();
		printf("Result: %i\n", result);
	}
	catch (std::exception e)
	{
		printf("%s\n", e.what());
	}

	//_CrtDumpMemoryLeaks();
	return 0;
}