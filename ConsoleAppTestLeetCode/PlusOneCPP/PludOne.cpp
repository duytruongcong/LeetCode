#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:

	static vector<int> plusOne(vector<int>& digits)
	{
		int total = 0;
		int j = 0;
		for (int i = digits.size() - 1; i >= 0; i--, j++)
		{
			total += digits[i] * pow(10, j);
		}

		cout << "total = " << total;

		//
		total += 1;

		//
		vector<int> result;
		int number = 0;

		while (total > 0)
		{
			number = total % 10;

			result.insert(result.begin(), number);

			total = total / 10;
		}

		return result;
	}

	static void PrintVector(vector<int> digits)
	{
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			cout << " " << digits.at(i) << " ";
		}
	}
};

int main()
{
	vector<int> vectorEx = { 5, 6, 1, 2, 3, 9 };
	vector<int> vectorResult;
	vectorResult = Solution::plusOne(vectorEx);

	Solution::PrintVector(vectorEx);
	cin.get();
}