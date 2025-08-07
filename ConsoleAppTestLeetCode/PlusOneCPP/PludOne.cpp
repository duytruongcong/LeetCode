#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

static class Solution
{
public:

	static vector<int> plusOneVersionOne(vector<int>& digits)
	{
		vector<int> result;
		int number = 0;
		int total = 0;

		if (digits.size() < 1 || digits.size() > 100)
		{
			cout << "digits must be: 1 <= digits.length <= 100" << endl;
			return result;
		}

		for (int i = 0; i < digits.size(); i++)
		{
			if (digits[i] < 0 || digits[i] > 9)
				return result;
		}

		if (digits[0] == 0)
		{
			return result;
		}

		for (int i = digits.size() - 1, j = 0; i >= 0; i--, j++)
		{
			total += digits[i] * pow(10, j);
		}

		cout << "total = " << total << endl;

		total += 1;

		while (total > 0)
		{
			number = total % 10;

			result.insert(result.begin(), number);

			total = total / 10;
		}

		return result;
	}

	static vector<int> plusOneVersionTwo(vector<int>& digits)
	{
		// Check vector's length
		if (digits.size() < 1 || digits.size() > 100)
		{
			cout << "Error! 1 <= digits'leng <= 100" << endl;
			return {};
		}

		// Check element
		for (int i = 0; i < digits.size(); ++i)
		{
			if (digits[i] < 0 || digits[i] > 9)
			{
				cout << "Error: digits[" << i << "] = " << digits[i] << " isn't in 0 to 9" << endl;
				return {};
			}
		}
		for (int i = digits.size() - 1; i >= 0; i--)
		{
			if (digits.at(i) < 9)
			{
				digits.at(i) += 1;
				return digits;
			}

			digits.at(i) = 0;
		}

		digits.insert(digits.begin(), 1);

		return digits;
	}

	static void PrintVector(vector<int> digits)
	{
		for (int digit : digits)
		{
			cout << " " << digit << " ";
		}
	}
};

int main()
{
	vector<int> vectorEx = { 1, 4, 9 };
	vector<int> vectorResult;
	vectorResult = Solution::plusOneVersionTwo(vectorEx);

	Solution::PrintVector(vectorResult);
	cin.get();
}