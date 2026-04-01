#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


void bubbleSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                // Swap them if they are in the wrong order
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    int left;
    int right;
    std::vector<std::vector<int>> resultFinal;
    std::vector<int> tmp;

    //sort
    bubbleSort(nums);

    //
    for (int i = 0; i < nums.size() - 2; i++)
    {
        left = i + 1;
        right = nums.size() - 1;
        while (left < right)
        {
            if((nums[i] + nums[left] + nums[right]) == 0)
            {
                tmp.push_back(nums[i]);
                tmp.push_back(nums[left]);
                tmp.push_back(nums[right]);

                resultFinal.push_back(tmp);
                break;
            }
            else if ((nums[i] + nums[left] + nums[right]) < 0)
            {
                left++;
            }
            else
            {
                right--;
            }
        }
    }

    return resultFinal;
}


int main()
{
    std::vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 9;
    std::vector<std::vector<int>> result;

    result = threeSum(nums);

    for (std::vector<int> x : result)
    {
        for (auto y : x)
        {
            std::cout << y << "|";
        }
        std::cout << std::endl;
    }

    return 0;
}