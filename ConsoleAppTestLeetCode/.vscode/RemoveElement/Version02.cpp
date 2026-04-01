#include <iostream>
#include <vector>

int RemoveElements(std::vector<int> &nums, int val)
{
    int n = nums.size();

    int i = 0;
    int k = 0;

    while (i < n)
    {
        if (nums.at(i) == val)
        {
            nums.at(i) = nums.at(n-1);

            n--;
        }
        else
        {
            i++;
        }
    }

    return n;
}

int main()
{
    // std::vector<int> nums = {2};
    std::vector<int> nums = {3, 2, 2, 3};

    int k = RemoveElements(nums, 3);

    std::cout << "k = " << k << std::endl;

    for (int x : nums)
    {
        std::cout << x << " | ";
    }

    return 0;
}