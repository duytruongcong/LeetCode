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
        Pool _pool;

        public LFUCache(int capacity)
        {
            _capacity = capacity;
            _cache = new Node[capacity];
            for (int i = 0; i < _cache.Length; i++)
            {
                _cache[i] = new Node();
            }

            _pool = new Pool(capacity);
        }

        public int Get(int key)
        {
            if (_cache != null)
            {
                foreach (Node node in _cache)
                {
                    if (node.Key == key)
                    {
                        node.Count++;
                        return node.Value;
                    }
                }
                return -1;
            }
            else
                return -1;
        }

        public void Put(int key, int value)
        {
            if (_cache != null)
            {
                //if existed, update
                foreach (Node node in _cache)
                {
                    if (node.Key == key)
                    {
                        node.Value = value;
                        node.Count++;

                        _pool.Push(key);

                        return;
                    }
                }

                //if not existed, insert if numberNode < _capacity
                var numberNode = GetNumberOfCache();
                if (numberNode < _capacity)
                {
                    //insert
                    for (int i = 0; i <= _cache.Length; i++)
                    {
                        if (_cache[i].Key == -1)
                        {
                            _cache[i].Key = key;
                            _cache[i].Value = value;
                            _cache[i].Count++;

                            _pool.Push(key);

                            return;
                        }
                    }
                }
                else
                {
                    //unvalidate LFU and insert

                    //get minCount
                    int minCount = GetMinCount(_cache);
                    int tmpKey = 0;

                    for (int i = 0; i < _cache.Length; i++)
                    {
                        if (_cache[i].Count == minCount)
                        {
                            tmpKey = _cache[i].Key;
                            break;
                        }
                    }

                    for (int i = 0; i < _cache.Length; i++)
                    {
                        if (_cache[i].Count == minCount)
                        {
                            tmpKey = _cache[i].Key;
                        }
                    }

                    //insert new
                    foreach (Node node in _cache)
                    {
                        if (node.Key == tmpKey)
                        {
                            node.Key = key;
                            node.Value = value;
                            node.Count = 1;
                        }
                    }
                }

                _queue.Enqueue(key);
            }
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
                    Console.WriteLine($"[{_cache[i].Key} | {_cache[i].Value} | {_cache[i].Count}]");
                }
            }
        }
    }

    public class Node
    {
        public int Key;
        public int Value;
        public int Count;

        public Node()
        {
            Key = -1;
            Value = -1;
            Count = 0;
        }
    }

    public class Pool
    {
        public int Capacity;
        public int[] Keys;
        private int Count = 0;

        public Pool(int capacity)
        {
            Capacity = capacity;
            Keys = new int[capacity];
        }

        public void Push(int key)
        {
            Keys[Count++] = key;

            if (Count == Capacity)
                Count = 0;
        }
    }

}
