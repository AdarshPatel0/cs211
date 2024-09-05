#include <iostream>

using namespace std;

int main()
{
	int const size = 10;
	int myNum = 10;
	double array[size] = {};
	cout << "Enter ten numbers: ";
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	double sum = 0;
	for (int i = 0; i < size; i++)
	{
		sum += array[i];
	}
	double average = sum / size;
	cout << "Average of entries in array: " << average << endl;
	double newSum = 0;
	int divisor = 0;
	for (int i = 0; i < size; i++)
	{
		if (array[i] > average)
		{
			newSum += array[i];
			divisor++;
		}
	}
	cout << "Average of entries greater than overall average: " << newSum / divisor << endl;
	return 0;
}