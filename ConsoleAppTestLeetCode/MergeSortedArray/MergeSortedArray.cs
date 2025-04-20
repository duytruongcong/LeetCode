using Utilities;

namespace MergedSortedArray
{
    class MergeSortedArray
    {
        static void Main()
        {
            int[] num1;
            int m = 5;
            int[] num2;
            int n = 3;

            Utility.InputArray(ref m, out num1);

            Utility.OutputArray(num1);

            Utility.SortNonDecreasingAray(num1);

            Utility.OutputArray(num1);

            //

            Utility.InputArray(ref n, out num2);

            Utility.OutputArray(num2);

            Utility.SortNonDecreasingAray(num2);

            Utility.OutputArray(num2);

            //

            int[] mergedArray = num1.Concat(num2).ToArray();

            Console.WriteLine($"Merged Array:\n");

            Utility.OutputArray(mergedArray);

            Utility.SortNonDecreasingAray(mergedArray);

            Utility.OutputArray(mergedArray);

            Console.ReadLine();
        }
    }
}





