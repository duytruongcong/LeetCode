#include <iostream>
#include <vector>

int calMaxAmount(std::vector<int> height)
{
    int amount = 0;
    int max = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j)
    {
        amount = (j - i) * std::min(height[i], height[j]);
        if (amount > max)
            max = amount;

        if (height[i] < height[j])
            i++;
        else
            j--;
    }

    return max;
}

int main()
{
    std::vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int max = calMaxAmount(height);

    std::cout << "Max = " << max << std::endl;

    return 0;
}