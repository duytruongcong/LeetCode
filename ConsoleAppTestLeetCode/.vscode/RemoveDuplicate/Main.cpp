#include <iostream>
#include <vector>

int RemoveDuplicateFromSortedArray(std::vector<int> &nums)
{
    if (nums.empty())
        return 0;

    int k = 1;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] != nums[k - 1])
        {
            nums[k] = nums[i];
            k++;
        }
    }

    std::cout << k << std::endl;

    return k;
}

int main()
{
    std::vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4, 5, 6, 6, 6, 7, 7, 7, 8};

    int k = RemoveDuplicateFromSortedArray(nums);

    for (int x : nums)
    {
        std::cout << x << " | ";
    }

    return 0;
}