#pragma once
#include "ItemType.h"

class List
{
private:
	ItemType data;
	List* next;

public:
	List():next(nullptr){}
	List(ItemType item);
	//~List();
	void InsertAfter(List* newNode);
	List* DeleteAfter();

};

