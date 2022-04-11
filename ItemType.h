#pragma once
class ItemType
{
public:
	int data;
	ItemType* next;
	ItemType(int data, ItemType* next) : data(data), next(next){};
};

