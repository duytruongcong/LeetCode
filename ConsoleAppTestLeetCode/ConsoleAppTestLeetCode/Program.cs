using ConsoleAppTestLeetCode;

LFUCache obj = new LFUCache(2);
Console.Write("null,\n");

int tmp;

obj.Put(1, 1);
obj.PrintKeyValue();
Console.WriteLine("null,\n");

obj.Put(2, 2);
obj.PrintKeyValue();
Console.WriteLine("null,\n");

tmp = obj.Get(1);
obj.PrintKeyValue();
Console.WriteLine(tmp + ",\n");

obj.Put(3, 3);
obj.PrintKeyValue();
Console.WriteLine("null,\n");

tmp = obj.Get(2);
obj.PrintKeyValue();
Console.WriteLine(tmp + ",\n");

tmp = obj.Get(3);
obj.PrintKeyValue();
Console.WriteLine(tmp + ",\n");

obj.Put(4, 4);
obj.PrintKeyValue();
Console.WriteLine("null,\n");

tmp = obj.Get(1);
obj.PrintKeyValue();
Console.WriteLine(tmp + ",\n");

tmp = obj.Get(3);
obj.PrintKeyValue();
Console.WriteLine(tmp + ",\n");

tmp = obj.Get(4);
obj.PrintKeyValue();
Console.WriteLine(tmp + ",\n");

