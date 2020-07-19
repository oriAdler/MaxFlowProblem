//-----------------------------------------------------------------------------------------------//
#ifndef __PRIORITYQUEUE_H_
#define __PRIORITYQUEUE_H_

#include <iostream>
#include <utility>
using namespace std;
//-----------------------------------------------------------------------------------------------//
// note: encapsulate???????

//class Pair
//{
//private:
//	int _key;
//	int _data;
//public:
//	Pair() = default;
//	Pair(const int newKey, const int newData)
//	{
//		_key = newKey;
//		_data = newData;
//	}
//	int first const { return _key; }
//	int getData() const { return _data; }
//	void setData(int data) { _data = data; }
//	bool operator <(const Pair& other) const
//	{
//		return _data < other._data;
//	}
//	bool operator >(const Pair& other) const
//	{
//		return _data > other._data;
//	}
//};

class PriorityQueue
{
private:
	pair<int, int>* _data = nullptr;
	int _MaxSize;
	int _PriorityQueueSize;
	int _allocated;
	int* _ptrArr;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixPriorityQueue(int node);
	void swapNodes(pair<int,int>& first, pair<int,int>& second);
	
public:
	PriorityQueue(int max);
	PriorityQueue(pair<int,int> arr[], int n);
	~PriorityQueue();
	pair<int,int> max();
	pair<int,int> deleteMax();
	void insert(pair<int,int> item);
	bool isEmpty() const;
	void increaseKey(int node, int newData);
};

//Swap nodes and update pointers.
inline void PriorityQueue::swapNodes(pair<int,int>& first, pair<int,int>& second)
{
	pair<int,int> temp = first;
	int firstIndex = _ptrArr[first.first];
	_ptrArr[first.first] = _ptrArr[second.first];
	_ptrArr[second.first] = firstIndex;
	first.swap(second);
}

#endif //__PRIORITYQUEUE_H_
