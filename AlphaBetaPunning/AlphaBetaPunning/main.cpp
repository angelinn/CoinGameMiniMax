#include <stdio.h>
#include <algorithm>
#include <vector>
#include "Game/CoinGame.h"

int main(int argc, const char* argv[])
{
	int coinCount = 5; // argv[1];
	{
		//CoinGame game(coinCount);
		//game.print();
		//int result = game.calculateWinner();
		//
		//game.print();

		//printf("Result: %i\n", result);

		std::vector<bool> a{ true, true, false, true, true };
		Node node(NULL, 5);
		node.board = a;
		std::vector<Node*> results;
		node.getAvailableMoves(results);

		//for (auto res : results)
		//{
		//	for (auto bo : res->board)
		//		printf("%s ", bo ? "1" : "0");
		//	printf("\n");
		//}
		//
		//std::vector<bool> copy;
		//int positions[2014];
		//int j = 0;
		//for (int i = 0; i < a.size(); ++i)
		//{
		//	if (a[i])
		//		copy.push_back(a[i]);
		//	else
		//		positions[j++] = i;
		//}
		//if (copy.size() > 1)
		//	copy[0] = false;

		//std::vector<std::vector<bool>> results;

		//do
		//{

		//	for (auto bo : copy)
		//		printf("%s ", bo ? "1" : "0");
		//	printf("\n");
		//	results.push_back(copy);
		//} while (std::next_permutation(copy.begin(), copy.end()));

		//printf("--------\n");

		//for (auto res : results)
		//{
		//	for (int i = 0; i < j; ++i)
		//		res.insert(res.begin() + positions[i], false);
		//	for (auto bo : res)
		//		printf("%s ", bo ? "1" : "0");
		//	printf("\n");
		//}
	}

	_CrtDumpMemoryLeaks();
	return 0;
}