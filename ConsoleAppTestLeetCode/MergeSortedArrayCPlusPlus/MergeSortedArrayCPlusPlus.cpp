
#include "../UtilityCPlusPlus/pch.h"
#include "../UtilityCPlusPlus/lib.h"

using namespace std;

int main()
{
	vector<int> num1;
	int m = 5;
	vector<int> num2;
	int n = 3;

	InputArray(m, num1);

	OutputArray(num1);

	SortNonDecreasingArray(num1);

	OutputArray(num1);

	//

	InputArray(n, num2);

	OutputArray(num2);

	SortNonDecreasingArray(num2);

	OutputArray(num2);

	//

	vector<int> mergedArray;
	mergedArray.reserve(num1.size() + num2.size());
	mergedArray.insert(mergedArray.end(), num1.begin(), num1.end());
	mergedArray.insert(mergedArray.end(), num2.begin(), num2.end());

	cout << "\n Merged Array:\n";

	OutputArray(mergedArray);

	SortNonDecreasingArray(mergedArray);

	OutputArray(mergedArray);
}


