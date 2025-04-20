using System;

class Program
{
    static void Main(string[] args)
    {
        int[] nums = { 1, 1, 2, 2, 2, 3, 3, 3, 3, 4, 4 };

        RemoveDuplicateNumber(ref nums);

        PrintOut(nums);

        System.Console.ReadLine();
    }

    static void RemoveDuplicateNumber(ref int[] nums)
    {
        int length = nums.Length;
        for (int i = 0; i < length; i++)
        {
            while (nums[i] == nums[i + 1])
            {
                for (int j = i + 1; j < length - 1; j++)
                {
                    nums[j] = nums[j + 1];
                }

                nums[length - 1] = 0;
                length--;
            }

            if (nums[i] == 0)
                break;
        }

        nums = nums.Where(x => x != 0).ToArray();
    }

    static void RemoveDuplicateNumberVer02(ref int[] num)
    {
        for (int i = 0; i < num.Length; i++)
        {
            for (int j = i + 1; j < num.Length; j++)
            {
                if(num[j] == num[i])
                {

                }
            }
        }

    }

    static void PrintOut(int[] nums)
    {
        //print out
        for (int i = 0; i < nums.Length; i++)
        {
            Console.Write($"{nums[i]} -> ");
        }
    }
}







