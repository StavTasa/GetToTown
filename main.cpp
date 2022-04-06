#include <iostream>

using namespace std;

void inputValdiationError(const char * msg)
{
	cout << msg << endl;
	exit(1);
	exit(1);
}

void setupTowns(int *towns, int num)
{
	for (int i = 0; i <= num; i++)
		towns[i] = 0;
}

void getRoadsInput(int *towns, int roads_length, int towns_length)
{
	int from, to;
	for (int i = 0; i < roads_length; i++)
	{
		cin >> from;
		cin >> to;
		if (to > towns_length || from > towns_length || from == to)
			inputValdiationError("Road definition input is invalid");
		towns[from] += to;
	}
}

int main()
{
	int towns_length, roads_length, *towns;
	cin >> towns_length;
	cin >> roads_length;
	cout << "towns: " << towns_length << endl;
	cout << "roads: " << roads_length << endl;

	towns = new int[towns_length];

	setupTowns(towns, towns_length);
	getRoadsInput(towns, towns_length, roads_length);

	for (int i = 0; i < roads_length; i++)
	{
		cout << towns[i] << endl;
	}



}