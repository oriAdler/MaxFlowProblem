//-----------------------------------------------------------------------------------------------//
#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_

#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------------------------//
// note: encapsulate???????

class KVPair
{
private:
	int _key;
	int _value;
public:
	KVPair() = default;
	KVPair(const int newKey, const int newValue)
	{
		_key = newKey;
		_value = newValue;
	}
	int getKey()
	{
		return _key;
	}
	int getValue()
	{
		return _value;
	}
	bool operator <(const KVPair& other) const
	{
		return _key < other._key;
	}
	bool operator >(const KVPair& other) const
	{
		return _key > other._key;
	}

};
class PriorityQueue
{

private:
	KVPair* _data=nullptr;
	int _MaxSize;
	int _PriorityQueueSize;
	int _allocated;

	PriorityQueue(int max);
	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixPriorityQueue(int node);

public:
	PriorityQueue(KVPair max);
	PriorityQueue(KVPair arr[], int n);
	~PriorityQueue();
	KVPair max();
	KVPair deleteMax();
	bool isEmpty() const;
	void insert(KVPair item);
};

#endif //__PRIORITYQUEUE_H_
