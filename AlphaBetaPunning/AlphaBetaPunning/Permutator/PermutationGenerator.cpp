#include "PermutationGenerator.h"
#include <algorithm>

typedef std::vector<std::vector<bool>> Permutations;
typedef std::vector<std::pair<size_t, size_t>> Indexes;
typedef std::vector<bool> Board;

Permutations PermutationGenerator::generatePermutations(const Board& board, size_t coins, size_t take)
{
	Indexes adjacentCoins;
	Permutations permutations;

	getAdjacentCoins(board, adjacentCoins);
	removeUnusableCoins(adjacentCoins, take);

	if (!adjacentCoins.size())
		return permutations;

	std::vector<int> amounts;
	addCurrentPermutations(permutations, adjacentCoins, board, take, amounts);

	printf("--------\n");

	putBackTakenCoins(permutations, adjacentCoins, board, amounts);

	printf("Next Iteration:\n");
	return permutations;
}

void PermutationGenerator::removeUnusableCoins(Indexes& indexes, size_t take)
{
	for (auto iter = indexes.begin(); iter != indexes.end(); ++iter)
	{
		if (((*iter).second - (*iter).first) < take)
		{
			iter = indexes.erase(iter);
			--iter;
		}
	}

}

void PermutationGenerator::getAdjacentCoins(const Board& board, Indexes& indexes)
{
	int j = 0;
	size_t start = 0;

	for (int i = 0; i < board.size(); ++i)
	{
		if (board[i])
		{
			start = i;
			for (j = i; true; ++j, ++i)
			{
				if (j >= board.size())
					j = i - board.size();

				if (!board[j])
					break;
			}
			indexes.push_back(std::pair<size_t, size_t>(start, j));
		}
	}
}

void PermutationGenerator::addCurrentPermutations(Permutations& permutations, Indexes& adjacentCoins,
												  const Board& board, size_t take, std::vector<int>& amount)
{
	printf("Got: \n");
	for (auto& adjacent : adjacentCoins)
	{
		for (int i = adjacent.first; i < adjacent.second; ++i)
			printf("%s ", board[i] ? "1" : "0");

		printf("\n");
	}

	Board current;

	int currentAmount = 0;
	for (auto& adjacent : adjacentCoins)
	{
		current = Board(board.begin() + adjacent.first, board.begin() + adjacent.second);
		for (int i = 0; i < take; ++i)
			current[i] = false;

		current = Board(current.begin() + take - 1, current.end());

		currentAmount = 0;
		do
		{
			Board full = current;
			auto takenCoin = std::find(full.begin(), full.end(), false);


			for (int i = 0; i < take - 1; ++i)
				takenCoin = full.insert(takenCoin, false);

			permutations.push_back(full);
			++currentAmount;
		} while (std::next_permutation(current.begin(), current.end()));
		amount.push_back(currentAmount);
	}
}

void PermutationGenerator::putBackTakenCoins(Permutations& permutations, Indexes& indexes, const Board& board, 
											 const std::vector<int>& amount)
{
	Board whole;

	int z = 0;
	int permCount = 0;

	for (auto& adjacent : indexes)
	{
		whole = board;
		for (int j = 0; j < amount[z]; ++j, ++permCount)
		{
			for (int i = adjacent.first, k = 0; i < adjacent.second; ++i, ++k)
				whole[i] = permutations[permCount][k];

			permutations[permCount] = whole;
			for (auto bo : permutations[permCount])
				printf("%s ", bo ? "1" : "0");
			printf("\n");
		}
		++z;
	}
}

void PermutationGenerator::generate(Permutations& permutations, size_t take, const Board& board)
{
	int i = 0;
	int got = 0;

	while (i < board.size())
	{
		got = 0;
		if (board[i])
		{
			Board current = board;
			++got;

			int j = i + 1;
			while (got < take)
			{
				if (j >= board.size())
					j -= board.size();

				if (board[j++])
					++got;
				else
				{
					got = -1;
					break;
				}
			}

			if (got > 0)
			{
				for (int k = i; got; ++k, --got)
				{
					if (k >= board.size())
						k -= board.size();

					current[k] = false;
				}

				permutations.push_back(current);
			}
		}
		++i;
	}
}