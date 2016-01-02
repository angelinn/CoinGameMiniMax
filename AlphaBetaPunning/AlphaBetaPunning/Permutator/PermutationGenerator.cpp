#include "PermutationGenerator.h"
#include <algorithm>

typedef std::vector<std::vector<bool>> Permutations;

Permutations PermutationGenerator::generatePermutations(const std::vector<bool>& board, size_t coins, size_t take)
{
	std::vector<bool> boardCopy;
	Permutations permutations;

	int* positions = new int[coins];
	size_t coinsAlreadyTaken = getNonTakenCoins(board, positions, boardCopy);

	if (boardCopy.size())
	{
		if (boardCopy.size() < take)
			return permutations;

		for (int i = 0; i < take; ++i)
			boardCopy[i] = false;
	}
	else
	{
		return permutations;
	}

	addCurrentPermutations(permutations, boardCopy);

	printf("--------\n");

	putBackTakenCoins(permutations, positions, coinsAlreadyTaken);

	delete positions;
	printf("Next Iteration:\n");
	return permutations;
}

size_t PermutationGenerator::getNonTakenCoins(const std::vector<bool>& board, int* positions,
											  std::vector<bool>& boardCopy)
{
	size_t coinsAlreadyTaken = 0;
	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i])
			boardCopy.push_back(board[i]);
		else
			positions[coinsAlreadyTaken++] = i;
	}

	return coinsAlreadyTaken;
}

void PermutationGenerator::addCurrentPermutations(Permutations& permutations, std::vector<bool>& board)
{
	std::vector<bool> permuted;
	printf("addCurrentPermutations\n");
	do
	{
		for (auto bo : board)
			printf("%s ", bo ? "1" : "0");
		printf("\n");

		permuted.clear();
		permuted = board;
		permutations.push_back(permuted);
	} while (std::next_permutation(board.begin(), board.end()));
}

void PermutationGenerator::putBackTakenCoins(Permutations& permutations, int* positions, size_t coinsAlreadyTaken)
{
	printf("putBackTakenCoins\n");
	for (int m = 0; m < permutations.size(); ++m)
	{
		for (int i = 0; i < coinsAlreadyTaken; ++i)
			permutations[m].insert(permutations[m].begin() + positions[i], false);
		for (auto bo : permutations[m])
			printf("%s ", bo ? "1" : "0");
		printf("\n");
	}
}