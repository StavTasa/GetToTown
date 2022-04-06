#include "List.h"

List::List(ItemType item)
{
	this->data = item;
	this->next = nullptr;
}

//List::~List()
//{
//}

void List::InsertAfter(List* newNode)
{
	newNode->next = next;
	next = newNode;
}

List* List::DeleteAfter()
{
	List* toDelete = next;

	if (toDelete == nullptr)
		return nullptr;
	next = toDelete->next;
	return toDelete;
}
