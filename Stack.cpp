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
	Node* temp;
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

void Stack::Push(ItemType item)
{
//	top = new Node(item);
}

//ItemType Stack::Pop(void)
//{
//	if (IsEmpty())
		//HANDLE ERROR

	//Node* temp = top;
	//ItemType item = top->data;
//	top = top->next;
	//delete temp;

	//return item;
//}
