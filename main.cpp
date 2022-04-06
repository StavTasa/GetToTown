#include <iostream>
#include "Node.h"
#include "ItemType.h"

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
		checkValidRoad(from, to, towns_length);
		node = new Node(to, towns[from]->next);

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

void GetToTown(int town_index, Node** towns, bool *visited, Node *approchables_head) {
	Node *node;

	if (visited[town_index])
		return;

	node = towns[town_index]->next;
	approchables_head->InsertAfter(new Node(town_index + 1, nullptr));
	visited[town_index] = true;

	
	while (node != nullptr)
	{
		GetToTown(node->data - 1, towns, visited, approchables_head);
		node = node->next;
	}
}

int main()
{
	int towns_length, roads_length, source;
	Node **towns;
	bool *visited;
	Node *approchables_head, *node;

	cin >> towns_length;
	cin >> roads_length;
	cout << "towns: " << towns_length << endl;
	cout << "roads: " << roads_length << endl;

	towns = getTowns(towns_length);
	getRoadsInput(towns, towns_length, roads_length);
	printRoads(towns, roads_length);

	cin >> source;
	checkValidTown(source, towns_length);
	
	visited = getEmptyVisited(towns_length);
	approchables_head = new Node(-1, nullptr);
	GetToTown(source - 1, towns, visited, approchables_head);

	cout << "visited: ";
	for (int i = 0; i < towns_length; i++)
	{
		cout << visited[i] << ", ";
	}
	cout << endl << "approchables: ";


	node = approchables_head->next;
	while (node != nullptr)
	{
		cout << node->data << ", ";
		node = node->next;
	}
}