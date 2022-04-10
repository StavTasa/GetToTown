#include "ArrayList.h"

ArrayList::ArrayList(int n) {
	arr = new NodeArrayList[n];
	headFree = 0;
	headList = -1;
	for (int i = 0; i < n-1; i++)
		arr[i].next = i+1;
	
}

void ArrayList::insert(int data)
{
	int loc = headFree;
	if (loc == -1)
	{
		std::cout << "Out of memory in ArrayList" << std::endl;
		exit(2);
	}
	headFree = arr[headFree].next;
	arr[loc].data = data;

	if (headList == -1)
	{
		headList = loc;
		arr[headList].next = -1;
	}
	else
	{
		arr[loc].next = headList;
		headList = loc;
	}



}
/*void ArrayList::deleteAfter(int node_index)
{
	int loc = arr[node_index].next;
	arr[node_index].next = arr[loc].next;
	arr[loc].next = headFree;
	headFree = loc;
}*/