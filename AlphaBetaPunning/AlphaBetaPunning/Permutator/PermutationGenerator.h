#ifndef PERMUTATOR_H
#define PERMUTATOR_H

#include <vector>


typedef std::vector<std::vector<bool>> Permutations;

class PermutationGenerator
{
public:
	Permutations generatePermutations(const std::vector<bool> &, size_t, size_t);

private:
	size_t getNonTakenCoins(const std::vector<bool> &, int *, std::vector<bool> &);
	void addCurrentPermutations(Permutations &, std::vector<bool> &);
	void putBackTakenCoins(Permutations&, int *, size_t);
};


#endif // PERMUTATOR_H
