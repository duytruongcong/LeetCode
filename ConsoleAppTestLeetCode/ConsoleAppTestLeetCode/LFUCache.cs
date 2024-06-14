using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleAppTestLeetCode
{
    public class LFUCache
    {
        int _capacity;
        Dictionary<int, int> _cache;

        public LFUCache(int capacity)
        {
            _capacity = capacity;
            _cache = new Dictionary<int, int>(capacity);
        }

        public int Get(int key)
        {
            if (_cache != null && _cache.ContainsKey(key))
                return _cache[key];
            else
                return -1;
        }

        public void Put(int key, int value)
        {
            _cache.Add(key, value);

            if (_cache.Count == _capacity)
            {

            }
        }
    }

    public class Node
    {
        public int Key;
        public int Value;
        public int Count = 0;
    }
}
