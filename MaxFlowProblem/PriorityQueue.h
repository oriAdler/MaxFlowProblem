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
	void setData(int data) { _data = data; }
	bool operator <(const Pair& other) const
	{
		return _data < other._data;
	}
	bool operator >(const Pair& other) const
	{
		return _data > other._data;
	}
};

class PriorityQueue
{
private:
	Pair* _data = nullptr;
	int _MaxSize;
	int _PriorityQueueSize;
	int _allocated;
	int* _ptrArr;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixPriorityQueue(int node);
	void swapNodes(Pair& first, Pair& second);
	
public:
	PriorityQueue(int max);
	PriorityQueue(Pair arr[], int n);
	~PriorityQueue();
	Pair max();
	Pair deleteMax();
	void insert(Pair item);
	bool isEmpty() const;
	void increaseKey(int node, int newData);
};

//Swap nodes and update pointers.
inline void PriorityQueue::swapNodes(Pair& first, Pair& second)
{
	Pair temp = first;
	int firstIndex = _ptrArr[first.getKey()];
	_ptrArr[first.getKey()] = _ptrArr[second.getKey()];
	first = second;
	_ptrArr[second.getKey()] = firstIndex;
	second = temp;
}

#endif //__PRIORITYQUEUE_H_
