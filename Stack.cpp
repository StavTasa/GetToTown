#include "Stack.h"

Stack::Stack()
{
	top = nullptr;
}

Stack::~Stack()
{
	MakeEmpty();
}

void Stack::MakeEmpty()
{
	List* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		selete temp;
	}
}

int Stack::IsEmpty()
{
	return (top == nullptr);
}

void Stack::Push(ItemType item)
{
	top = new List(item, top);
}

ItemType Stack::Pop(void)
{
	if (IsEmpty())
		//HANDLE ERROR

	List* temp = top;
	ItemType item = top->data;
	top = top->next;
	delete temp;

	return item;
}
