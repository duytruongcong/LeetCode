#include <iostream>
#include <string>
#include <array>
#include<vector>
using namespace std;

int RemoveElement(int* const arrNums, const int value, int sizeOfArray)
{
	int k = 0;

	for (int i = 0; i < sizeOfArray; i++)
	{
		if (value != arrNums[i])
		{
			arrNums[k] = arrNums[i];
			k++;
		}
	}

	return k;
}

void PrintArray(const int* const array, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << array[i] << " - ";
	}

	cout << endl;
}

int main()
{
	int size = 12;
	int* nums = new int[size] { 2,3,3,5,6,7,7,9,7,7,8,1 };

	int val = 7;

	int sizeOfExpectedNums = 0;

	PrintArray(nums, size);

	sizeOfExpectedNums = RemoveElement(nums, val, size);

	PrintArray(nums, sizeOfExpectedNums);

	delete[] nums;

	cin.get();
	return 0;
}