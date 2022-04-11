#pragma once
#include "Node.h"
#include "ItemType.h"

class Stack
{
private:
	ItemType* top;

public:
	Stack();
	~Stack();
	void MakeEmpty();
	int IsEmpty();
	void Push(int item);
	int Pop();
};