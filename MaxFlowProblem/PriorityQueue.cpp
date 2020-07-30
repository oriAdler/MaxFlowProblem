
#include "PriorityQueue.h"

//Constructor only receives size and allocated proper memory
PriorityQueue::PriorityQueue(int max)
{
	_data = new pair<int, int>[max];
	_MaxSize = max;
	_PriorityQueueSize = 0;
	_allocated = 1;
	_ptrArr = new int[max];
}
//Constructor receives array of pairs and creates sorted priority queue with updated ptr array(index in queue) to every object
PriorityQueue::PriorityQueue(pair<int, int> arr[], int n)
{
	_PriorityQueueSize = _MaxSize = n;

	_data = arr;	//Assign array A to data pointer.
	_allocated = 0; //Memory not allocated by heap.
	_ptrArr = new int[n];

	//Init ptr array
	for (int i = 0; i < _MaxSize; i++) //note: maxSize vs currentSize?
	{
		_ptrArr[_data[i].first] = i;
	}

	for (int j = n / 2 - 1; j >= 0; j--) // floyd algorithm.
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
	if (left < _PriorityQueueSize && _data[left].second > _data[node].second)
	{
		max = left;
	}
	else
	{
		max = node;
	}
	if (right < _PriorityQueueSize && _data[right].second > _data[max].second)
	{
		max = right;
	}
	//Swap values if necessary and continue fixing the heap towards the leaves.
	if (max != node)
	{
		swapNodes(_data[node], _data[max]);
		fixPriorityQueue(max);
	}
}

PriorityQueue::~PriorityQueue()
{
	//check if array is allocated, if true delete
	if (_allocated)
	{
		delete[] _data;
	}
	_data = nullptr;
	delete[] _ptrArr;
}
// this method will delete max item in priority queue and fix priority queue accordingly
// complexity: O(log n) (fixPriorityQueue)
pair<int, int> PriorityQueue::deleteMax()
{
	if (_PriorityQueueSize < 1)
	{
		cout << "Error: EMPTY Priority Queue\n";
		exit(1);
	}
	pair<int, int> max = _data[0];
	_PriorityQueueSize--;
	//Using swap in order to update pointers
	swapNodes(_data[0], _data[_PriorityQueueSize]);
	fixPriorityQueue(0);
	return max;
}

bool PriorityQueue::isEmpty() const
{
	return !_PriorityQueueSize;
}
//this method recieves key number to update the key with new data
//1. we find node location with index number and then we will increase key
// complexity => O(1) (due to ptr array)
//2. fix PriorityQueue accordingly
// complexity => O(log n) (node change only travel up because key is increased)

void PriorityQueue::increaseKey(int node, int newData)
{
	int i = _ptrArr[node]; //Extract node's location
	_data[i].second = newData;
	//The increased node will trickle up until the priority queue is fixed.
	while ((i > 0) && (_data[Parent(i)].second < _data[i].second))
	{
		swapNodes(_data[i], _data[Parent(i)]);
		i = Parent(i);
	}
}

pair<int, int> PriorityQueue::max()
{
	if (_PriorityQueueSize < 1)
	{
		std::cout << "Error: EMPTY PriorityQueue\n";
		exit(1);
	}
	return _data[0];
}
//insert into priority queue
// complexity => O(log n)
void PriorityQueue::insert(pair<int, int> item)
{
	if (_PriorityQueueSize == _MaxSize)
	{
		cout << "Error: Priority Queue FULL\n";
		exit(1);
	}
	int i = _PriorityQueueSize;
	_PriorityQueueSize++;

	_data[i] = item;		 //Insert item to most left leaf.
	_ptrArr[item.first] = i; //Update item's pointer.

	//trickle up tree
	while ((i > 0) && (_data[Parent(i)].second < _data[i].second))
	{
		swapNodes(_data[i], _data[Parent(i)]);
		i = Parent(i);
	}
}
