//-----------------------------------------------------------------------------------------------//
#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(int max)
{
	_data = new Pair[max];
	_MaxSize = max;
	_PriorityQueueSize = 0;
	_allocated = 1;
}

// note: function  Pair? 
PriorityQueue::PriorityQueue(Pair arr[], int n)
{
	_PriorityQueueSize = _MaxSize = n;

	_data = arr;
	_allocated = 0;

	for (int j = n / 2 - 1; j >= 0; j--)	// floyd algorithm.
	{
		fixPriorityQueue(j);
	}
}

int PriorityQueue::Left(int node)
{
	return (2 * node + 1);
}

int PriorityQueue::Right(int node)
{
	return (2 * node + 2);
}

int PriorityQueue::Parent(int node)
{
	return (node - 1) / 2;
}

void PriorityQueue::fixPriorityQueue(int node)
{
	int max;
	int left = Left(node);
	int right = Right(node);

	//Find maximum among node, left and right
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
	//Swap values if necessary and continue fixing the heap towards the leaves.
	if (max != node)
	{
		swap(_data[node], _data[max]);	// note: swap from utility?
		fixPriorityQueue(max);
	}
}

PriorityQueue::~PriorityQueue()
{
	if (_allocated)
	{
		delete[]_data;
	}
	_data = nullptr;
}

Pair PriorityQueue::deleteMax()
{
	if (_PriorityQueueSize < 1)
	{
		cout << "Error: EMPTY Priority Queue\n";
		exit(1);
	}
	Pair max = _data[0];
	_PriorityQueueSize--;
	_data[0] = _data[_PriorityQueueSize];
	fixPriorityQueue(0);
	return max;
}

bool PriorityQueue::isEmpty() const
{
	return !_PriorityQueueSize;
}

Pair PriorityQueue::max()
{
	if (_PriorityQueueSize < 1)
	{
		std::cout << "Error: EMPTY PriorityQueue\n";
		exit(1);
	}
	return _data[0];
}

void PriorityQueue::insert(Pair item)
{
	if (_PriorityQueueSize == _MaxSize)
	{
		cout << "Error: Priority Queue FULL\n";
		exit(1);
	}
	int i = _PriorityQueueSize;
	_PriorityQueueSize++;

	while ((i > 0) && (_data[Parent(i)] < item))
	{
		_data[i] = _data[Parent(i)];
		i = Parent(i);
	}
	_data[i] = item;
}
//-----------------------------------------------------------------------------------------------//
