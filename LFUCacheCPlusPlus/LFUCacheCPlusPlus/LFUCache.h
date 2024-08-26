#pragma once

class LFUCache
{
public:
	int _capacity;
	Node* _cache;

	LFUCache(int capacity)
	{
		_capacity = capacity;
		_cache = new Node[capacity];

		for (int i = 0; i <= capacity; i++)
		{
			_cache[i] = new Node();
		}
	}

	~LFUCache()
	{
		delete _cache;
		_cache = nullptr;
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

