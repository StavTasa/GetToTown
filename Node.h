#pragma once

class Node
{
public:
	Node* next;
	int data;

	Node(int data, Node* next) : data(data), next(next) {};
	//~List();
	void InsertAfter(Node* newNode);
	Node* DeleteAfter();

};

