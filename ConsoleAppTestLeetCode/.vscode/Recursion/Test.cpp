#include <iostream>
#include <vector>

void PrintArray(std::vector<int> &array)
{
    for (int element : array)
    {
        std::cout << element << " - ";
    }
}

int Fact(int n)
{
    if (n == 1)
        return 1;

    return n * Fact(n - 1);
}

int Sum(int n)
{
    if (n == 0)
        return 0;

    return (n + Sum(n - 1));
}

void ReverseArray(std::vector<int> &nums, int left, int right)
{
    if (left >= right)
        return;

    std::swap(nums[left], nums[right]);

    ReverseArray(nums, left + 1, right - 1);
}

int Fibonacci(int n)
{
    if (n <= 1)
        return n;

    // std::cout << n << " - ";

    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

void PrintFibonacci(int n)
{
    int nSubTwo = 0;
    int nSubOne = 1;

    int sum;

    std::cout << nSubTwo << " - " << nSubOne << " - ";

    int i = 2;

    while (i <= n)
    {
        sum = nSubOne + nSubTwo;

        std::cout << sum << " - ";

        nSubTwo = nSubOne;

        nSubOne = sum;

        i++;
    }
}

int main()
{
    // std::cout << Fact(5) << std::endl;
    // std::cout << Sum(5) << std::endl;
    // std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    // ReverseArray(nums, 0, nums.size() - 1);
    // PrintArray(nums);
    // std::cout << Fibonacci(8);

    PrintFibonacci(17);

    return 0;
}