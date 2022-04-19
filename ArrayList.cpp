#include "ArrayList.h"

ArrayList::ArrayList(int n) {
	arr = new NodeArrayList[n];
	headFree = 0;
	headList = -1;
	for (int i = 0; i < n - 1; i++)
		arr[i].next = i + 1;

}

ArrayList::~ArrayList() {
	delete arr;
}


void ArrayList::insert(int data) //last
{
	int loc = headFree, i;
	if (loc == -1)
	{
		std::cout << "Out of memory in ArrayList" << std::endl;
		exit(2);
	}
	headFree = arr[headFree].next;
	arr[loc].data = data;
	arr[loc].next = -1;


	if (headList == -1)
	{
		headList = loc;
		arr[headList].next = -1;
	}
	else {
		i = headList;
		while (arr[i].next != -1)
			i = arr[i].next;
		arr[i].next = loc;
	}
}
void ArrayList::deleteHead()
{
	int temp_i = headList;
	headList = arr[headList].next;

	arr[temp_i].next = headFree;
	headFree = temp_i;
	
}