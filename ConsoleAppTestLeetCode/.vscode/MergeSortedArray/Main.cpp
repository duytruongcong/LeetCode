#include <iostream>
#include <vector>

void MergeSortedArray(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int tmp = m;
    int sizeOfNums1 = nums1.size();

    for (int element2 : nums2)
    {
        for (int j = 0; j < tmp; j++)
        {
            if (nums1[j] > element2)
            {
                nums1.insert(nums1.begin() + j, element2);
                tmp++;
                break;
            }
        }
    }
}

void PrintArray(std::vector<int> &array)
{
    for (int element : array)
    {
        std::cout << element << " - ";
    }
}

int main()
{
    std::vector<int> nums1 = {5, 7, 8, 10, 13, 0, 0, 0};
    std::vector<int> nums2 = {4, 6, 9};

    MergeSortedArray(nums1, 5, nums2, 3);

    PrintArray(nums1);

    return 0;
}