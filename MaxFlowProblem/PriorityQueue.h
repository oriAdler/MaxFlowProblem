//-----------------------------------------------------------------------------------------------//
#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_

#include <iostream>
using namespace std;
//-----------------------------------------------------------------------------------------------//
// note: encapsulate???????

class Pair
{
private:
	int _key;
	int _data;
public:
	Pair() = default;
	Pair(const int newKey, const int newData)
	{
		_key = newKey;
		_data = newData;
	}
	int getKey() const { return _key; }
	int getData() const { return _data; }
	bool operator <(const Pair& other) const
	{
		return _key < other._key;
	}
	bool operator >(const Pair& other) const
	{
		return _key > other._key;
	}
};

class PriorityQueue
{
private:
	Pair* _data = nullptr;
	int _MaxSize;
	int _PriorityQueueSize;
	int _allocated;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixPriorityQueue(int node);

public:
	PriorityQueue(int max);
	PriorityQueue(Pair arr[], int n);
	~PriorityQueue();
	Pair max();
	Pair deleteMax();
	void insert(Pair item);
	bool isEmpty() const;
	//void increaseKey(place, newKey);	//Note: implement increaseKey
};

#endif //__PRIORITYQUEUE_H_
