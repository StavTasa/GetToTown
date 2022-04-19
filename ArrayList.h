#pragma once
#include <iostream>
#include "NodeArrayList.h"

class ArrayList
{
	public:
		ArrayList(int n);
		~ArrayList();
		NodeArrayList * arr;
		int headFree;
		int headList;
		void insert(int data);
		void deleteHead();
};

