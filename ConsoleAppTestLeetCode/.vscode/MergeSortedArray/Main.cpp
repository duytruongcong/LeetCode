#include <iostream>

int main()
{
    int nums1[] = {5, 7, 8, 10, 13, 0, 0, 0};
    int nums2[] = {4, 6, 9};
    int m = 5;
    int n = 3;
    int tmp = m;
    int sizeOfNums1 = 8;


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < tmp; j++)
        {
            if (nums1[j] > nums2[i])
            {
                //dich chuyen cac phan tu qua phai 1
                for (int k = sizeOfNums1-1; k > j; k--)
                {
                    nums1[k] = nums1[k - 1];
                }

                //
                nums1[j] = nums2[i];
                tmp++;
                break;
            }
        }
    }

    //in mang nums1
    for(int i=0;i<sizeOfNums1;i++)
    {
        std::cout << nums1[i] << " - ";
    }

    return 0;
}