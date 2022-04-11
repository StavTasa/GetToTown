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
	ItemType* temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

int Stack::IsEmpty()
{
	return (top == nullptr);
}

void Stack::Push(int item)
{
	top = new ItemType(item, top);
}

int Stack::Pop()
{
	if (IsEmpty())
		//HANDLE ERROR

	ItemType* temp = top;
	int data = top->data;
	top = top->next;
	//delete temp;

	return data;
}