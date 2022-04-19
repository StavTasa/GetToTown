#include "Node.h"

void Node::InsertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}

Node* Node::DeleteAfter()
{
	Node* toDelete = next;

	if (toDelete == nullptr)
		return nullptr;
	next = toDelete->next;
	return toDelete;
}
