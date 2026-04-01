#include <iostream>
#include <vector>

void SortColor(std::vector<int> &nums)
{
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            std::swap(nums[mid++], nums[low++]);
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            std::swap(nums[mid], nums[high--]);
        }
    }
}

int main()
{
    std::vector<int> nums = {2, 2, 2, 1, 1, 1};
    // std::vector<int> nums = {2, 1, 0};

    SortColor(nums);

    for (auto x : nums)
    {
        std::cout << x << " | " << std::endl;
    }

    return 0;
}

/// truong hop mid == high