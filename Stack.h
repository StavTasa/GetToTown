#pragma once
#include "List.h"
#include "ItemType.h"
class Stack
{
private:
	List* top;

public:
	Stack();
	~Stack();
	void MakeEmpty();
	int IsEmpty();
	void Push(ItemType item);
	ItemType Pop(void);
};

