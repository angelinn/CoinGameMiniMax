#ifndef NODE_H
#define NODE_H

#include <vector>

#define NO_VALUE -1
#define MAX_COINS 1024

class Node
{
public:

	Node(Node *, size_t, int);

	int evaluate(bool);
	int evaluateRec(Node *, bool);

public:
	Node* parent;
	std::vector<Node *> children;
	int value;
	std::vector<bool> board;
	size_t coins;

public:
	bool getAvailableMoves(std::vector<Node*> &) const;

private:
	Node(const Node &) = delete;
	Node& operator=(const Node &) = delete;
};


#endif // NODE_H
