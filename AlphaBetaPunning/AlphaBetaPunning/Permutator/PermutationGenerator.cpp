#include "PermutationGenerator.h"

typedef std::vector<std::vector<bool>> Permutations;
typedef std::vector<bool> Board;

#define NOTHING -1
#define GOT_SOMETHING(got) got > 0

void PermutationGenerator::generate(Permutations& permutations, size_t take, const Board& board)
{
	int got = 0;
	Board current;

	for (int i = 0; i < board.size(); ++i)
	{
		got = 0;
		if (board[i])
		{
			current = board;
			++got;

			for (int j = i + 1; got < take; ++j)
			{
				if (j >= board.size())
					j -= board.size();

				if (board[j])
					++got;
				else
				{
					got = NOTHING;
					break;
				}
			}

			if (GOT_SOMETHING(got))
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
	}
}