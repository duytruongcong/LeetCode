// pch.cpp: source file corresponding to the pre-compiled header
#include "pch.h"
#include "lib.h"

void InputArray(int& number, std::vector<int>& array)
{
	std::cout << "\n Please input the number = ";

	while (!(std::cin >> number))
	{
		std::cin.clear();// xoa trang thai loi
		std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');

		std::cout << "Value is invalid\n";
		std::cout << "Please input the number";
	}

	array.resize(number);
	std::srand(static_cast<unsigned int>(std::time(nullptr)));//khoi tao seed cho rand()

	for (int i = 0; i < number; ++i)
	{
		array[i] = std::rand() % 10 + 1;
	}

}

void OutputArray(std::vector<int> array)
{
	cout << "\n";

	for (int i = 0; i < array.size(); i++)
	{
		cout << array[i] << " ";

		if (i < (array.size() - 1))
		{
			cout << "| ";
		}

	}
}

void SortNonDecreasingArray(vector<int>& array)
{
	int tmpNum;

	for (int i = 0; i < array.size() - 1; i++)
	{
		int minPosition = i;

		int min = array[i];

		for (int j = i + 1; j < array.size(); j++)
		{
			if (min > array[j])
			{
				min = array[j];

				minPosition = j;
			}
		}

		//swap
		if (minPosition != i)
		{
			tmpNum = array[i];

			array[i] = min;

			array[minPosition] = tmpNum;
		}
	}
}

