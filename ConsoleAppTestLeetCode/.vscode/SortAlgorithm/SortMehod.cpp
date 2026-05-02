#include <iostream>
#include <vector>

void Print(std::vector<int> &nums)
{
    int size = nums.size();

    for (int i = 0; i < size; i++)
    {
        std::cout << "(" << i << ") ";
    }

    std::cout << std::endl;

    for (int i = 0; i < size; i++)
    {
        std::cout << " " << nums[i] << " |";
    }

    std::cout << std::endl;
    std::cout << std::endl;
}

void PrintHighlight(const std::vector<int> &nums, int j)
{
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == j)
            std::cout << "[" << nums[i] << "] ";
        else
            std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
}

void InsertionSort(std::vector<int> &nums)
{
    int i, j, temp;

    int sizeOfArray = nums.size();

    for (i = 1; i < sizeOfArray; i++)
    {
        temp = nums[i];

        for (j = i; j > 0 && nums[j - 1] > temp; j--)
        {
            nums[j] = nums[j - 1];
        }

        nums[j] = temp;
        PrintHighlight(nums, j);
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

void SelectionDoubleSort(std::vector<int> &nums)
{
    int left = 0;
    int right = nums.size() - 1;
    int minIndex, maxIndex;

    while (left < right)
    {
        /* code */
        minIndex = left;
        maxIndex = right;

        for (int i = left; i <= right; i++)
        {

            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        std::swap(nums[minIndex], nums[left]);

        if (maxIndex == left)
            maxIndex = minIndex;

        std::swap(nums[maxIndex], nums[right]);

        left++;
        right--;
    }
}

void BubleSort(std::vector<int> &nums)
{
    int length = nums.size();
    bool isSorted = false;

    for (int i = 0; i < length - 1; i++)
    {
        isSorted = true;
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (nums[j] > nums[j + 1])
            {
                std::swap(nums[j], nums[j + 1]);
                isSorted = false;
            }

            if (isSorted)
                return;
        }
    }
}

void ShellSort(std::vector<int> &nums)
{
    int sizeOfArray = nums.size();
    int temp, j;

    for (int gap = sizeOfArray / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < sizeOfArray; i++)
        {
            temp = nums[i];

            for (j = i; j >= gap && nums[j - gap] > temp; j -= gap)
            {
                nums[j] = nums[j - gap];
            }

            nums[j] = temp;
        }
    }
}

void MaxHeapNode(std::vector<int> &nums, int n, int i)
{
    int max = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && nums[left] > nums[max])
        max = left;

    if (right < n && nums[right] > nums[max])
        max = right;

    if (max != i)
    {
        std::swap(nums[i], nums[max]);
        MaxHeapNode(nums, n, max);
    }
}

void MaxHeapSort(std::vector<int> &nums, int n)
{
    for (int i = (n - 1) / 2; i >= 0; i--)
    {
        MaxHeapNode(nums, n, i);
    }
}

void HeapSort(std::vector<int> &nums, int n)
{
    for (int i = n; i > 1; i--)
    {
        MaxHeapSort(nums, i);
        std::swap(nums[0], nums[i - 1]);
    }
}

int main()
{
    std::vector<int> nums = {3, 2, 0, 5, 8, 4, 7, 1, 8, 6, 9};
    // std::vector<int> nums = {56, 34, 72, 3, 20, 31, 47, 10, 79, 15, 83, 40};

    // InsertionSort(nums);
    //   SelectionSort(nums);
    //  SelectionDoubleSort(nums);
    //  BubleSort(nums);
    // ShellSort(nums);
    HeapSort(nums, nums.size());

    Print(nums);

    return 0;
}