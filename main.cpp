#include <iostream>
#include "Node.h"
#include "ItemType.h"
#include "ArrayList.h"

using namespace std;

void inputValdiationError(const char * msg)
{
	cout << msg << endl;
	exit(1);
}

void checkValidTown(int town_number, int towns_length)
{
	if (town_number < 1)
		inputValdiationError("Road cant point to negetive number");

	if (town_number > towns_length)
		inputValdiationError("Invalid town number");
}

Node** getTowns(int num)
{
	Node **towns = new Node*[num];
	for (int i = 0; i <= num; i++)
		towns[i] = new Node(-1, nullptr);

	return towns;
}

void checkValidRoad(int from, int to, int towns_length)
{
	checkValidTown(from, towns_length);
	checkValidTown(to, towns_length);

	if (from == to)
		inputValdiationError("Road definition input is invalid");
}

void getRoadsInput(Node **towns, int roads_length, int towns_length)
{
	int from, to;
	Node *node;

	for (int i = 0; i < roads_length; i++)
	{
		cin >> from;
		cin >> to;
		checkValidRoad(from , to, towns_length);
		node = new Node(to - 1, towns[from]->next);

		// TODO: is roads 1 -> 2, 1 -> 2 ok? or invalid
		towns[from - 1]->InsertAfter(node);
	}
}

void printTownRoads(Node *node)
{
	node = node->next;
	if (node == nullptr)
		cout << "No roads";
	while (node != nullptr)
	{
		cout << " -> " << node->data << ",";
		node = node->next;
	}
	cout << endl;
}

void printRoads(Node **towns, int roads_length) {
	Node *node;
	for (int i = 0; i < roads_length; i++)
	{
		cout << i + 1 << ": "; 
		printTownRoads(towns[i]);
	}
}

bool *getEmptyVisited(int towns_length)
{
	bool *visited = new bool[towns_length];
	for (int i = 0; i < towns_length; i++)
		visited[i] = false;

	return visited;
}


void GetToTown(int town_index, Node** towns, bool *visited, ArrayList *approchables) {
	Node *node;

	if (visited[town_index])
		return;

	approchables->insert(town_index);
	visited[town_index] = true;

	node = towns[town_index]->next;
	while (node != nullptr)
	{
		GetToTown(node->data, towns, visited, approchables);
		node = node->next;

	}
	/*
	stack.push(source)
	while stack is not empty:
		parent = stack.pop
		if !visited[parent];
			visited[parent] = true

			node = towns[parent]->next;
			while (node != nullptr)
				stack.push(node->to)
	*/
}

ArrayList *getApprochables(int source, Node **towns,int towns_length) {
	ArrayList *approchables = new ArrayList(towns_length);
	bool *visited = getEmptyVisited(towns_length);

	GetToTown(source - 1, towns, visited, approchables);
	return approchables;
}

void printApprochables(ArrayList *approchables) {
	int i = approchables->headList;
	cout << '{';
	while (i != -1)
	{
		cout << approchables->arr[i].data + 1 << ", ";
		i = approchables->arr[i].next;
	}
	cout << '}' << endl;
}

int main()
{
	int towns_length, roads_length, source;
	Node **towns;
	ArrayList *approchables;

	cin >> towns_length;
	cin >> roads_length;
	cout << "towns: " << towns_length << endl;
	cout << "roads: " << roads_length << endl;

	towns = getTowns(towns_length);
	getRoadsInput(towns, roads_length, towns_length);
	//printRoads(towns, roads_length);

	cin >> source;
	checkValidTown(source, towns_length);


	approchables = getApprochables(source, towns, towns_length);
	cout << endl << "approchables: " << endl;
	printApprochables(approchables);
}
