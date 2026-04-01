#include <iostream>
#include <vector>

void MoveZeroes(std::vector<int> &nums)
{
    int k = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] != 0)
        {
            std::swap(nums[i], nums[k++]);
        }
    }
}

int main()
{
    std::vector<int> nums = {0, 2, 3, 4, 0, 5};

    MoveZeroes(nums);

    for (auto x : nums)
    {
        std::cout << x << " | ";
    }

    return 0;
}