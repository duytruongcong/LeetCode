#include <iostream>
#include <vector>

void SortColor(std::vector<int> &nums)
{
    int min = 0;
    int tmp = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        min = i;

        for (int j = i; j < nums.size(); j++)
        {
            if (nums[min] > nums[j])
            {
                min = j;
            }
        }
        tmp = nums[i];
        nums[i] = nums[min];
        nums[min] = tmp;
    }
}

int main()
{
    // std::vector<int> nums = {2, 0, 2, 1, 1, 0};
    std::vector<int> nums = {2, 1, 0};

    SortColor(nums);

    for (auto x : nums)
    {
        std::cout << x << " | " << std::endl;
    }

    return 0;
}