#include <stdio.h>
#include <vector>
#include "Permutator\PermutationGenerator.h"
#include "Game\CoinGame.h"

int main(int argc, const char* argv[])
{
	int coinCount = 3; // argv[1];

	try
	{
		std::vector<bool> a{ true, true, true, true, true };

		PermutationGenerator gen;
		Permutations perm;

		for (int i = 0; i < 3; ++i)
		{
			gen.generate(perm, i + 1, a);
		}

		for (auto& pe : perm)
		{
			for (auto bo : pe)
				printf("%s ", bo ? "1" : "0");
			printf("\n");
		}
		printf("------------\n");

		//PermutationGenerator generator;
		//generator.generatePermutations(a, 5, 1);
		//generator.generatePermutations(a, 5, 2);
		//generator.generatePermutations(a, 5, 3);

		//Node node(NULL, a.size());
		//node.board = a;
		//std::vector<Node*> results;
		//node.getAvailableMoves(results);

		//CoinGame game(coinCount);
		//game.calculateWinner();
		//game.print();
	}
	catch (std::exception e)
	{
		printf("%s\n", e.what());
	}

	_CrtDumpMemoryLeaks();
	return 0;
}