namespace Utilities
{
    public static class Utility
    {
        public static void InputArray(ref int number, out int[] array)
        {
            Console.Write($"Please input {nameof(number)} = ");

            while (!int.TryParse(Console.ReadLine(), out number))
            {
                Console.WriteLine("Value is invalid");
            }

            array = new int[number];
            Random random = new Random();

            for (int i = 0; i < array.Length; i++)
            {
                array[i] = random.Next(1, 11);
            }
        }

        public static void OutputArray(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                Console.Write($"{array[i]} ");
                Console.Write(i < array.Length - 1 ? "| " : "");
            }
            Console.WriteLine();
        }

        public static void SortNonDecreasingAray(int[] array)
        {
            int tmpNum;

            for (int i = 0; i < array.Length - 1; i++)
            {
                int minPosition = i;

                int min = array[i];

                for (int j = i + 1; j < array.Length; j++)
                {
                    if (min > array[j])
                    {
                        min = array[j];

                        minPosition = j;
                    }
                }

                //swap
                if (minPosition != i)
                {
                    tmpNum = array[i];

                    array[i] = min;

                    array[minPosition] = tmpNum;
                }
            }
        }
    }
}
