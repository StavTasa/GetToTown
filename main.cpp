#include <iostream>
#include "Node.h"
#include "ItemType.h"
#include "ArrayList.h"
#include "Stack.h"
#include <string.h>
#include <sstream>

using namespace std;

void inputValdiationError(const char * msg)
{
	cout << msg << endl;
	exit(1);
}

void checkValidTown(int town_number, int towns_length)
{
	if (town_number < 1)
		inputValdiationError("Invalid input");

	if (town_number > towns_length)
		inputValdiationError("Invalid input");
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
	int from, to, i = 0;
	Node *node, *temp_node;

	string s;

	getline(cin, s);
	s.append(" ");
	if (s == " ")
		return;
	string delimiter = " ";

	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		if (i % 2 == 0)
			from = stoi(token);
		else
		{
			to = stoi(token);
			checkValidRoad(from, to, towns_length);
			node = new Node(to - 1, towns[from]->next);

			temp_node = towns[from - 1];
			while (temp_node->next != NULL)
				temp_node = temp_node->next;

			temp_node->InsertAfter(node);
		}
		i++;
		if (i / 2 > roads_length)
			inputValdiationError("Invalid input");
		s.erase(0, pos + delimiter.length());

	}
	if (i / 2 != roads_length)
		inputValdiationError("Invalid input");

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


void GetToTownRecu(int town_index, Node** towns, bool *visited, ArrayList *approchables) {
	Node *node;

	if (visited[town_index])
		return;

	visited[town_index] = true;
	approchables->insert(town_index);

	node = towns[town_index]->next;
	while (node != nullptr)
	{
		GetToTownRecu(node->data, towns, visited, approchables);
		node = node->next;

	}
}

void GetToTownIter(int town_index, Node** towns, bool *visited, ArrayList *approchables) {
	Stack stack, stack_temp;
	Node *node;
	stack.Push(town_index);
	while (!stack.IsEmpty()) {
		town_index = stack.Pop();
		if (!visited[town_index])
		{
			approchables->insert(town_index);
			visited[town_index] = true;

			node = towns[town_index]->next;
			while (node != nullptr)
			{
				stack_temp.Push(node->data);
				node = node->next;
			}
			while (!stack_temp.IsEmpty())
				stack.Push(stack_temp.Pop());
		}
	}
}

ArrayList *getApprochablesR(int source, Node **towns, int towns_length) {
	ArrayList *approchables = new ArrayList(towns_length);
	bool *visited = getEmptyVisited(towns_length);

	GetToTownRecu(source - 1, towns, visited, approchables);
	return approchables;
}

ArrayList *getApprochablesI(int source, Node **towns, int towns_length) {
	ArrayList *approchables = new ArrayList(towns_length);
	bool *visited = getEmptyVisited(towns_length);

	GetToTownIter(source - 1, towns, visited, approchables);
	return approchables;
}


void printApprochables(ArrayList *approchables) {
	int i = approchables->headList;
	while (i != -1)
	{
		cout << approchables->arr[i].data + 1 << " ";
		i = approchables->arr[i].next;
	}
}


int main()
{
	int towns_length, roads_length, source;
	Node **towns;
	ArrayList *approchables;

	cin >> towns_length;
	cin >> roads_length;
	getchar();

	if (towns_length < 0 || roads_length < 0)
		inputValdiationError("Invalid input");
		

	towns = getTowns(towns_length);
	getRoadsInput(towns, roads_length, towns_length);

	cin >> source;
	checkValidTown(source, towns_length);


	approchables = getApprochablesR(source, towns, towns_length);
	cout << endl << "Cities accessible from source city " << source << " (recursive algorithm): ";
	printApprochables(approchables);

	approchables = getApprochablesI(source, towns, towns_length);
	cout << endl << "Cities accessible from city source city " << source << " (iterative algorithm): " ;
	printApprochables(approchables);

}
