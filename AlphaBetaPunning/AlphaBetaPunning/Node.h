#ifndef NODE_H
#define NODE_H

#include <list>

#define NO_VALUE -1

struct Node
{
	Node* parent = NULL;
	std::list<Node *> children;
	int value = NO_VALUE;

	Node(Node* par) : parent(par), value(-1)
	{  }

	int evaluate(bool max)
	{
		return evaluateRec(parent, max);
	}

	int evaluateRec(Node* current, bool max)
	{
		for (auto child : current->children)
		{
			if (current->value == NO_VALUE || (max && child->value > current->value) || (!max && child->value < current->value))
				current->value = child->value;
		}

		if (current->parent == NULL)
			return current->value;

		return evaluateRec(current->parent, !max);
	}
};


#endif // NODE_H
