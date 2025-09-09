#include <iostream>
#include <string>
#include <array>
using namespace std;

int RemoveElement(int value, int nums[], int sizeOfNums)
{
	for (int i = 0; i < sizeOfNums; i++)
	{
		while (value == nums[i])
		{
			for (int j = i; j < sizeOfNums; j++)
			{
				nums[j] = nums[j+1];
			}

			sizeOfNums--;
		}
	}

	return sizeOfNums;
}

void PrintArray(const int* array, const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << array[i] << " - ";
	}

	cout << endl;
}

int main()
{
	int nums[] = { 2,3,3,5,6,7,7,9,7,7,8,1, };

	int sizeOfNums = sizeof(nums) / sizeof(int);

	int val = 7;

	int sizeOfExpectedNums = 0;

	PrintArray(nums, sizeOfNums);

	sizeOfExpectedNums = RemoveElement(val, nums, sizeOfNums);

	int* expectedNums = new int[sizeOfExpectedNums];

	for (int i = 0; i < sizeOfExpectedNums; i++)
	{
		expectedNums[i] = nums[i];
	}

	//PrintArray(nums);

	PrintArray(expectedNums, sizeOfExpectedNums);

	cin.get();
	return 0;
}