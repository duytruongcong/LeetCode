#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> TwoSum(std::vector<int> &nums, int target)
{
    std::unordered_map<int, int> map;

    int need;

    for (int i = 0; i < nums.size(); i++)
    {
        need = target - nums[i];

        if (map.count(need) != 0)
            return {map[need], i};
        else
            map.insert({nums[i], i});
    }

    return {};
}


int main()
{
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> result;

    result = TwoSum(nums, target);

    for (int x : result)
        std::cout << x << "|";

    return 0;
}