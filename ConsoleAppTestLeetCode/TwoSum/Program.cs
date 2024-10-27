
int number;
int[] nums = new int[10];
Random random = new Random();
for (int i = 0; i < nums.Count(); i++)
{
    nums[i] = random.Next(1, 10);
}
Console.WriteLine("Array is:");

for (int i = 0; i < nums.Count(); i++)
{
    Console.Write($"({i}){nums[i]} -> ");
}


Console.WriteLine("\n Enter an integer number:");
number = int.Parse(Console.ReadLine());

//
for (int i = 0; i < nums.Count(); i++)
{
    for (int j = i + 1; j < nums.Count(); j++)
    {
        if ((nums[i] + nums[j]) == number)
        {
            Console.WriteLine($"({i}){nums[i]} | ({j}){nums[j]}");
        }
    }
}

Console.ReadLine();
