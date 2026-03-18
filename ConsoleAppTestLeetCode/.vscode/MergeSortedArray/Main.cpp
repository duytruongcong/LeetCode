#include <iostream>
#include <vector>

void MergeSortedArray(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int p = nums1.size();
    int i = m - 1;
    int j = n - 1;
    int k = p - 1;

    while (i != 0 && j != 0)
    {
        if (nums1.at(i) > nums2.at(j))
        {
            nums1.at(k) = nums1.at(i);
            i--;
        }
        else
        {
            nums1.at(k) = nums2.at(j);
            j--;
        }

        k--;
    }

    while (j >= 0)
    {
        nums1[k--] = nums2[j--];
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