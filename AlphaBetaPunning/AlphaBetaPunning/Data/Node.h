#ifndef NODE_H
#define NODE_H

#include <vector>

#define NO_VALUE -1

class Node
{
public:

	Node(Node *, size_t);
	~Node();

	int evaluate(bool, int);

public:
	Node* parent;
	int value;
	size_t coins;

public:
	std::vector<bool> board;
	std::vector<Node *> children;

public:
	bool getAvailableMoves();

private:
	Node(const Node &) = delete;
	Node& operator=(const Node &) = delete;
};


#endif // NODE_H
