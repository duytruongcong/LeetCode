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
                        node.DateTime = DateTime.Now;
                        node.Count++;
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
                            _cache[i].DateTime = DateTime.Now;
                            _cache[i].Count++;
                            return;
                        }
                    }
                }
                else
                {
                    //unvalidate LFU and insert

                    //tim minCount
                    int minCount = GetMinCount(_cache);
                    int tmpKey = 0;
                    DateTime tmpDateTime = DateTime.MinValue;

                    for (int i = 0; i < _cache.Length; i++)
                    {
                        if (_cache[i].Count == minCount)
                        {
                            tmpKey = _cache[i].Key;
                            tmpDateTime = _cache[i].DateTime;//lay duoc datime node dau tien
                            break;
                        }
                    }

                    for (int i = 0; i < _cache.Length; i++)
                    {
                        if (_cache[i].Count == minCount)
                        {
                            tmpKey = _cache[i].Key;
                            if (tmpDateTime > _cache[i].DateTime)
                                tmpDateTime = _cache[i].DateTime;
                        }
                    }

                    //insert new
                    foreach (Node node in _cache)
                    {
                        if (node.Key == tmpKey && node.DateTime == tmpDateTime)
                        {
                            node.Key = key;
                            node.Value = value;
                            node.DateTime = DateTime.Now;
                            node.Count = 1;
                        }
                    }
                }
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
    }

    public class Node
    {
        public int Key;
        public int Value;
        public int Count;
        public DateTime DateTime;

        public Node()
        {
            Key = -1;
            Value = -1;
            Count = 0;
        }
    }
}
