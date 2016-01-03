#ifndef PERMUTATOR_H
#define PERMUTATOR_H

#include <vector>

typedef std::vector<std::vector<bool>> Permutations;
typedef std::vector<std::pair<size_t, size_t>> Indexes;
typedef std::vector<bool> Board;

class PermutationGenerator
{
public:
	void generate(Permutations &, size_t, const Board &);
	Permutations generatePermutations(const Board &, size_t, size_t);

private:
	void getAdjacentCoins(const Board &, Indexes &);
	void removeUnusableCoins(Indexes &, size_t);
	void addCurrentPermutations(Permutations &, Indexes &, const Board& board, size_t, std::vector<int> &);
	void putBackTakenCoins(Permutations &, Indexes &, const Board& board, const std::vector<int> &);
};


#endif // PERMUTATOR_H
