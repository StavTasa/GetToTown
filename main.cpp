#include <iostream>

using namespace std;
void setup_towns(int *towns, int num)
{
	for (int i = 0; i <= num; i++)
		towns[i] = 0;
}

void get_roads_input(int *towns, int road_number)
{
	int from, to;
	for (int i = 0; i < road_number; i++)
	{
		cin >> from;
		cin >> to;
		towns[from] += to;
	}
}

int main()
{
	int town_number, road_number, *towns;
	cin >> town_number;
	cin >> road_number;
	cout << "towns: " << town_number << endl;
	cout << "roads: " << road_number << endl;

	towns = new int[town_number];

	setup_towns(towns, town_number);
	get_roads_input(towns, road_number);

	for (int i = 0; i < road_number; i++)
	{
		cout << towns[i] << endl;
	}



}

