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
    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (nums[j] < nums[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
            std::swap(nums[i], nums[minIndex]);
    }
}

void SelectionDoubleSort(std::vector<int>& nums)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int minIndex = left;
        int maxIndex = right;

        for (int i = left; i <= right; i++)
        {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        std::swap(nums[left], nums[minIndex]);

        // fix nếu max bị ảnh hưởng
        if (maxIndex == left)
            maxIndex = minIndex;//muc dich de lam gi

        std::swap(nums[right], nums[maxIndex]);

        left++;
        right--;
    }
}

int main()
{
    std::vector<int> nums = {3, 2, 10, 5, 8, 4, 7};

    //InsertionSort(nums);
    // SelectionSort(nums);
    SelectionDoubleSort(nums);

    for (int x : nums)
    {
        std::cout << x << "|";
    }

    return 0;
}