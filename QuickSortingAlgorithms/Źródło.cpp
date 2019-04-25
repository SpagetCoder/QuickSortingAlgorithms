#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


void quicksort(vector<int>& data, int left, int right)
{
	int pivot, s;

	if (left < right)
	{
		pivot = data[left];
		s = left;

		for (int i = left + 1; i < right; i++)
		{
			if (data[i] < pivot)
			{
				s++;
				swap(data[s], data[i]);
			}
		}
		swap(data[s], data[left]);
		quicksort(data, left, s);
		quicksort(data, s + 1, right);
	}
}

void check_if_sorted(vector<int>& data)
{
	int i = 1;
	int is_sorted = true;

	while ((i < data.size() && is_sorted))
	{
		if (data[i - 1] > data[i])
			is_sorted = false;

		i++;
	}

	if (!is_sorted)
		cout << "ERROR - DATA NOT SORTED" << endl << endl;

	else
		cout << "Data is sorted" << endl << endl;

}


int main(int argc, char *argv[])
{
	int size;
	cout << "Give me number of elemets" << endl;
	cin >> size;

	vector <int> data;
	vector <int> data2;

	srand((unsigned)time(0));

	for (int i = 0; i < size; i++)
	{
		data.push_back((rand() % size) + 1);
	}

	auto start = chrono::high_resolution_clock::now();

	data2 = data;
	quicksort(data2, 0, data2.size());

	auto finish = chrono::high_resolution_clock::now();
	chrono::duration<double> elapsed = finish - start;
	cout << "quicksort sort time " << elapsed.count() << endl;

	check_if_sorted(data2);

	system("pause");

}