#pragma once

#include <iostream>
#include <utility>
using namespace std;

//Using pair when all the 'first' elements are unique keys
//associated with their 'second' value objects.
// in order in implement find O(1), we used an addtional array to track the array of index of every object in PriorityQueue
// Key = vertex #
// Value = min capacity on path to same vertex
class PriorityQueue
{
private:
	pair<int, int> *_data = nullptr;
	int _MaxSize;
	int _PriorityQueueSize;
	int _allocated;
	int *_ptrArr;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixPriorityQueue(int node);
	void swapNodes(pair<int, int> &first, pair<int, int> &second);

public:
	PriorityQueue(int max);
	PriorityQueue(pair<int, int> arr[], int n);
	~PriorityQueue();
	pair<int, int> max();
	pair<int, int> deleteMax();
	void insert(pair<int, int> item);
	bool isEmpty() const;
	void increaseKey(int node, int newData);
};

//Swap nodes and update "pointers" in ptr array.
inline void PriorityQueue::swapNodes(pair<int, int> &first, pair<int, int> &second)
{
	pair<int, int> temp = first;
	int firstIndex = _ptrArr[first.first];
	_ptrArr[first.first] = _ptrArr[second.first];
	_ptrArr[second.first] = firstIndex;
	first.swap(second);
}
