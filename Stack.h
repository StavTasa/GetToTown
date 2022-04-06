#pragma once
#include "Node.h"
#include "ItemType.h"
class Stack
{
private:
	Node* top;

public:
	Stack();
	~Stack();
	void MakeEmpty();
	int IsEmpty();
	void Push(ItemType item);
	ItemType Pop(void);
};

