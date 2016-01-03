#ifndef PERMUTATOR_H
#define PERMUTATOR_H

#include <vector>

typedef std::vector<std::vector<bool>> Permutations;
typedef std::vector<bool> Board;

class PermutationGenerator
{
public:
	static void generate(Permutations &, size_t, const Board &);
};


#endif // PERMUTATOR_H
