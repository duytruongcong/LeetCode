
public class LRUCache
{
    public int _capacity;
    public Dictionary<int, int> _cache;

    public LRUCache(int capacity)
    {
        _capacity = capacity;
    }

    public void Put(int key, int value)
    {

    }

    public int Get(int key)
    {
        return 1;
    }
}

public class Node
{
    public int Key;
    public int Value;
    public int Count;
    public Node(int key, int value, int count)
    {
            Key  = key; Value = value; Count = count;
    }
}
