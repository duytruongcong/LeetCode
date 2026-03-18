#include <iostream>
#include <vector>

int RemoveElements(std::vector<int> &nums, int val)
{
    int k = 0;
    int frontCursor = 0;
    int tmpSwap;
    int backCursor = nums.size() - 1;
    bool fLeft = false;
    bool fRight = false;

    if (nums.empty())
        return 0;

    while (1)
    {

        if (frontCursor > backCursor)
        {
            break;
        }

        if (nums.at(frontCursor) != val)
        {
            k++;
            frontCursor++;
            fLeft = false;
        }
        else
        {
            fLeft = true;
        }

        if (nums.at(backCursor) == val)
        {
            backCursor--;
            fRight = false;
        }
        else
        {
            fRight = true;
        }

        if (fLeft && fRight)
        {
            tmpSwap = nums.at(frontCursor);
            nums.at(frontCursor) = nums.at(backCursor);
            nums.at(backCursor) = tmpSwap;
            k++;
            frontCursor++;
            backCursor--;
        }
    }

    return k;
}

int main()
{
    std::vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

    int k = RemoveElements(nums, 2);

    std::cout << "k = " << k << std::endl;

    for (int x : nums)
    {
        std::cout << x << " | ";
    }

    return 0;
}