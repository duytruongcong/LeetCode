#include "LFUCache.h"

class LFUCache
{
public:
	int _capacity;
	Node _pCache[];

	LFUCache(int capacity)
	{
		_capacity = capacity;
		_pCache = new Node[capacity];

		for (int i = 0; i <= capacity; i++)
		{
			*(_pCache + i) = (Node*)calloc;
		}
	}

	~LFUCache()
	{
		delete _pCache;
		_pCache = nullptr;
	}
};

class Node
{
public:
	int Key;
	int Value;
	int Count;
	int Old;

	Node()
	{
		Key = -1;
		Value = -1;
		Count = 0;
		Old = 0;
	}
};