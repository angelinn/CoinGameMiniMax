#include <stdio.h>

#include "CoinGame.h"

int main(int argc, const char* argv[])
{
	int coinCount = 5; // argv[1];
	{
		CoinGame game;
		game.print();
		int result = game.calculateWinner();
		
		game.print();

		printf("Result: %i\n", result);
	}

	_CrtDumpMemoryLeaks();
	return 0;
}