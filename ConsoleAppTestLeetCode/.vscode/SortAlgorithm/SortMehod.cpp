#include <iostream>
#include <vector>

void InsertionSort(std::vector<int> &nums)
{
    int i, j;
    int size = nums.size();
    for (i = 1; i < size; i++)
    {
        int key = nums[i];

        j = i;

        while (j > 0 && nums[j - 1] > key)
        {
            nums[j] = nums[j - 1];
            j--;
        }

        nums[j] = key;
    }
}

void SelectionSort(std::vector<int> &nums)
{
    int minIndex;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(nums[i], nums[minIndex]);
    }
}

int main()
{
    std::vector<int> nums = {3, 2, 10, 5, 8, 4, 7};

    InsertionSort(nums);
    // SelectionSort(nums);

    for (int x : nums)
    {
        std::cout << x << "|";
    }

    return 0;
}