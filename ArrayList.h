#pragma once
#include <iostream>
#include "NodeArrayList.h"

class ArrayList
{
	public:
		ArrayList(int n);
		NodeArrayList * arr;
		int headFree;
		int headList;
		void insert(int data);
		void deleteAfter(int node);
};

