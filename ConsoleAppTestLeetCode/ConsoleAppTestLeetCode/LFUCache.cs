using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace ConsoleAppTestLeetCode
{
    public class LFUCache
    {
        int _capacity;
        Node[] _cache;

        public LFUCache(int capacity)
        {
            _capacity = capacity;
            _cache = new Node[capacity];
            for (int i = 0; i < _cache.Length; i++)
            {
                _cache[i] = new Node();
            }
        }

        public int Get(int key)
        {
            int result = -1;

            if (_cache != null)
            {
                foreach (Node node in _cache)
                {
                    if (node.Key == key)
                    {
                        node.Count++;
                        node.Old = 0;
                        result = node.Value;
                    }
                    else
                    {
                        node.Old++;
                    }
                }
            }
            
            return result;
        }

        public void Put(int key, int value)
        {
            bool hasKey = false;

            if (_cache != null)
            {
                //if existed, update
                foreach (Node node in _cache)
                {
                    if (node.Key == key)
                    {
                        node.Value = value;
                        node.Count++;
                        node.Old = 0;

                        hasKey = true;
                    }
                    else
                    {
                        node.Old++;
                    }
                }

                if (hasKey == true)
                    return;

                //if not existed, insert if numberNode < _capacity
                var numberNode = GetNumberOfCache();
                if (numberNode < _capacity)
                {
                    //insert
                    for (int i = 0; i < _cache.Length; i++)
                    {
                        if (_cache[i].Key == -1)
                        {
                            _cache[i].Key = key;
                            _cache[i].Value = value;
                            _cache[i].Count++;
                            _cache[i].Old = 0;

                            return;
                        }
                    }
                }
                else
                {
                    //unvalidate LFU and insert

                    //get minCount
                    int minCount = GetMinCount(_cache);
                    List<int> listKey = new List<int>();

                    for (int i = 0; i < _cache.Length; i++)
                    {
                        if (_cache[i].Count == minCount)
                        {
                            listKey.Add(_cache[i].Key);
                        }
                    }

                    // tu lisKey, tim ra max Old

                    (int keyResult, int maxOld) = GetMaxOldFromListKey(_cache, listKey);


                    //insert
                    foreach (Node node in _cache)
                    {
                        if (node.Key == keyResult)
                        {
                            node.Key = key;
                            node.Value = value;
                            node.Count = 1;
                            node.Old = 0;
                        }
                    }
                }
            }
        }

        private (int key, int maxOld) GetMaxOldFromListKey(Node[] cache, List<int> listKey)
        {
            int maxOld = 0;
            int keyResult = 0;
            int tmpOld = 0;

            foreach (int key in listKey)
            {
                tmpOld = GetOldFromKey(key);

                if (maxOld <= tmpOld)
                {
                    maxOld = tmpOld;
                    keyResult = key;
                }
            }
            return (keyResult, maxOld);
        }

        int GetOldFromKey(int key)
        {
            foreach (Node node in _cache)
            {
                if (node.Key == key)
                {
                    return node.Old;
                }
            }

            return 0;
        }

        private int GetMinCount(Node[] cache)
        {
            int min = cache[0].Count; // Assume first element is the minimum

            for (int i = 1; i < cache.Length; i++)
            {
                if (cache[i].Count < min)
                {
                    min = cache[i].Count;
                }
            }

            return min;
        }

        private int GetNumberOfCache()
        {
            int number = 0;
            foreach (Node node in _cache)
            {
                if (node.Key != -1)
                {
                    number++;
                }
            }
            return number;
        }

        public void PrintKeyValue()
        {
            for (int i = 0; i < _cache.Length; i++)
            {
                if (_cache[i] == null)
                {
                    Console.WriteLine($"node{i} null");
                }
                else
                {
                    Console.WriteLine($"[Key: {_cache[i].Key} |Value: {_cache[i].Value} |Count: {_cache[i].Count} |Old: {_cache[i].Old}]");
                }
            }
        }
    }

    public class Node
    {
        public int Key;
        public int Value;
        public int Count;
        public int Old;

        public Node()
        {
            Key = -1;
            Value = -1;
            Count = 0;
            Old = 0;
        }
    }
}
