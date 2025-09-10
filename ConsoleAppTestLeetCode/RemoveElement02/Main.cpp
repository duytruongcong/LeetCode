#include <iostream>
#include <string>
#include <array>
#include<vector>
using namespace std;

int RemoveElement(vector<int>& array, const int value, int sizeOfArray)
{
	int k = 0;

	for (int i = 0; i < sizeOfArray; i++)
	{
		if (value != array[i])
		{
			array[k] = array[i];
			k++;
		}
	}

	return k;
}

void PrintArray(const vector<int> array, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << array[i] << " - ";
	}

	cout << endl;
}

int main()
{
	vector<int> nums = { 2,3,3,5,6,7,7,9,7,7,8,1 };

	int val = 7;

	int sizeOfExpectedNums = 0;

	PrintArray(nums, nums.size());

	sizeOfExpectedNums = RemoveElement(nums, val, nums.size());

	PrintArray(nums, sizeOfExpectedNums);


	cin.get();
	return 0;
}