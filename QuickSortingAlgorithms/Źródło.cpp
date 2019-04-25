#include <cstdlib> 
#include <ctime> 
#include <iostream>
#include <chrono>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

int medianPivot(vector<int>&data, int left, int right)
{
	srand(time(NULL));
	int a = left + rand() % (right - left);
	int b = min(left + 1 + rand() % (right - left),right);
	int c = min(left + 2 + rand() % (right - left), right);
	int median;

	if (a < b && a > c || a > b && a < c)
	{
		median = a;
	}
	else if (b < a && b > c || b > a && b < c)
	{
		median = b;
	}
	else
	{
		median = c;
	}

	swap(data[median], data[right]);

	int pivot = data[right];
	int i = (left - 1); 

	for (int j = left; j <= right - 1; j++)
	{

		if (data[j] <= pivot)
		{
			i++;
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[right]);
	return (i + 1);
}

void quicksortMedian(vector<int>& data, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = medianPivot(data, left, right);

		quicksortMedian(data, left, pivot - 1);
		quicksortMedian(data, pivot + 1, right);
	}
}

int randomPivot(vector<int>&data, int left, int right)
{
	srand(time(NULL));
	int random = left + rand() % (right - left);
	swap(data[random], data[right]);

	int pivot = data[right]; 
	int i = (left - 1); 

	for (int j = left; j <= right - 1; j++) 
	{

		if (data[j] <= pivot)
		{
			i++; 
			swap(data[i], data[j]);
		}
	}
	swap(data[i + 1], data[right]);
	return (i + 1);
}

void quicksortWithRandomPivot(vector<int>& data, int left, int right)
{
	int pivot;

	if (left < right)
	{
		pivot = randomPivot(data, left, right);

		quicksortWithRandomPivot(data, left, pivot - 1);
		quicksortWithRandomPivot(data, pivot + 1, right);
	}
}


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

void insertionSort(vector <int>& data)
{
	int value_min, j;

	for (int i = 1; i < data.size(); i++)
	{
		value_min = data[i];
		j = i - 1;

		while (j >= 0 && value_min < data[j])
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j + 1] = value_min;
	}

}

void quicksortWithInsertion(vector<int>& data, int left, int right)
{
	int pivot, s;

	if (left < right)
	{

		if (right - left < 10)
			insertionSort(data);

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


	start = chrono::high_resolution_clock::now();
	data2 = data;
	quicksortWithRandomPivot(data2, 0, data2.size());
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "quicksort sort with random pivot time " << elapsed.count() << endl;
	check_if_sorted(data2);

	start = chrono::high_resolution_clock::now();
	data2 = data;
	quicksortMedian(data2, 0, data2.size());
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "quicksort sort with median of three " << elapsed.count() << endl;
	check_if_sorted(data2);

	start = chrono::high_resolution_clock::now();
	data2 = data;
	quicksortWithInsertion(data2, 0, data2.size());
	finish = chrono::high_resolution_clock::now();
	elapsed = finish - start;
	cout << "quicksort sort with insertion " << elapsed.count() << endl;
	check_if_sorted(data2);

	system("pause");

}