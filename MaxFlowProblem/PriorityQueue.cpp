//-----------------------------------------------------------------------------------------------//
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int max)
{
	_data = new KVPair [max];
	_MaxSize = max;
	_PriorityQueueSize = 0;
	_allocated = 1;
}

//-----------------------------------------------------------------------------------------------//
// note: function  KVPair? 
PriorityQueue::PriorityQueue(KVPair arr[], int n)
{
	_PriorityQueueSize = _MaxSize = n;

	_data = new KVPair[_MaxSize];
	_allocated = 0;
	//for (int i = 0; i < n; i++)	// makes a copy of the original array.
	//{
	//	_data[i] = arr[i];
	//}

	for (int j = n / 2 - 1; j >= 0; j--)	// floyd algorithm.
		fixPriorityQueue(j);
}
//-----------------------------------------------------------------------------------------------//
int PriorityQueue::Left(int node)
{
	return (2 * node + 1);
}
//-----------------------------------------------------------------------------------------------//
int PriorityQueue::Right(int node)
{
	return (2 * node + 2);
}
//-----------------------------------------------------------------------------------------------//
int PriorityQueue::Parent(int node)
{
	return (node - 1) / 2;
}
//-----------------------------------------------------------------------------------------------//
// some changes in the order of if-else terms, in order to count exectly comparion number.
void PriorityQueue::fixPriorityQueue(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	// _key is id, person has '>' operator which compare id's.
	if (left < _PriorityQueueSize && _data[left] > _data[node])
	{
		max = left;
	}
	else
	{
		max = node;
	}
	if (right < _PriorityQueueSize && _data[right] > _data[max])
	{
		max = right;
	}
	if (max != node)
	{
		// note: swap
		fixPriorityQueue(max);
	}
}
//-----------------------------------------------------------------------------------------------//

PriorityQueue::~PriorityQueue()
{
	if (_allocated)
	{
		delete[]_data;
	}
	_data = nullptr;
}
//-----------------------------------------------------------------------------------------------//
KVPair PriorityQueue::deleteMax()
{
	if (_PriorityQueueSize < 1)
	{
		cout << "Error: EMPTY PriorityQueue\n";
		exit(1);
	}
	KVPair max = _data[0];
	_PriorityQueueSize--;
	_data[0] = _data[_PriorityQueueSize];
	fixPriorityQueue(0);
	return max;
}

bool PriorityQueue::isEmpty() const
{
	return !_PriorityQueueSize;
}

//-----------------------------------------------------------------------------------------------//
KVPair PriorityQueue::max()
{
	if (_PriorityQueueSize < 1)
	{
		std::cout << "Error: EMPTY PriorityQueue\n";
		exit(1);
	}
	return _data[0];
}
//-----------------------------------------------------------------------------------------------//
void PriorityQueue::insert(KVPair item)
{
	if (_PriorityQueueSize == _MaxSize)
	{
		cout << "Error: PriorityQueue FULL\n";
		exit(1);
	}
	int i = _PriorityQueueSize;
	_PriorityQueueSize++;

	while ((i > 0) && (_data[Parent(i)].getKey() < item.getKey()))
	{
		_data[i] = _data[Parent(i)];
		i = Parent(i);
	}
	_data[i] = item;
}
//-----------------------------------------------------------------------------------------------//
