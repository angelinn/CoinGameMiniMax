#include <stdio.h>
#include "Permutator\PermutationGenerator.h"
#include "Game\CoinGame.h"
#include "Data\Node.h"

int main(int argc, const char* argv[])
{
	try
	{
		if (argc < 2)
			throw std::exception("You must specify a value for coin amount.");

		int coinCount = atoi(argv[1]);

		if (coinCount < 1)
			throw std::out_of_range("CoinAmount is an invalid value.");

		CoinGame game(coinCount);
		CoinGameResult result = game.calculateWinner();

		printf("Result: [%i, %i, %i]\n", result.i, result.count, result.moves);
	}
	catch (std::exception e)
	{
		printf("%s\n", e.what());
	}

	return 0;
}