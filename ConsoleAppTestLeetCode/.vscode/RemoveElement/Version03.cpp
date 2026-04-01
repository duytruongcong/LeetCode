#include <iostream>
#include <vector>

int RemoveElement(std::vector<int> &nums, int val)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        if (nums[left] == val)
        {
            nums[left] = nums[right];
            right--;
        }
        else
        {
            left++;
        }
    }

    return left;
}

int main()
{
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

    int k = RemoveElement(nums, 2);

    for (auto x : nums)
    {
        std::cout << x << "|";
    }

    return 0;
}