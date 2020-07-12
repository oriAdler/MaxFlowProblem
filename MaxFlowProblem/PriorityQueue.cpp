//-----------------------------------------------------------------------------------------------//
#include "heap.h"
//-----------------------------------------------------------------------------------------------//
// Average case: θ(n + klogn).
Person* Heap::selectHeap(Person* arr[], int n, int k, int& numComp)
{
	Heap heap(arr, n, numComp);

	for (int i = 0; i < k - 1; i++)
	{
		Person* temp = heap.deleteMin(numComp);
		delete temp;
	}

	return heap.deleteMin(numComp);
}
//-----------------------------------------------------------------------------------------------//
Heap::Heap(int max)
{
	_data = new Person*[max];
	_MaxSize = max;
	_heapSize = 0;
	_allocated = 1;
}
//-----------------------------------------------------------------------------------------------//
int Heap::Left(int node)
{
	return (2 * node + 1);
}
//-----------------------------------------------------------------------------------------------//
int Heap::Right(int node)
{
	return (2 * node + 2);
}
//-----------------------------------------------------------------------------------------------//
int Heap::Parent(int node)
{
	return (node - 1) / 2;
}
//-----------------------------------------------------------------------------------------------//
// some changes in the order of if-else terms, in order to count exectly comparion number.
void Heap::fixHeap(int node, int& numComp)
{
	int min;
	int left = Left(node);
	int right = Right(node);

	// key is id, person has '>' operator which compare id's.
	if (left < _heapSize)
	{
		numComp++;
		if (!(*(_data[left]) > *(_data[node])))	// *_data[left] < *_data[node]
			min = left;
		else	// *_data[left] > *_data[node]
			min = node;
	}
	else	// left child not exist.
		min = node;
	// find minimum between right and min(left, node).
	if (right < _heapSize)
	{
		numComp++;
		if (!(*(_data[right]) > *(_data[min])))
			min = right;
	}

	if (min != node)
	{
		swap(_data[node], _data[min]);
		fixHeap(min, numComp);
	}
}
//-----------------------------------------------------------------------------------------------//
Heap::Heap(Person* arr[], int n, int& numComp)
{
	_heapSize = _MaxSize = n;

	_data = new Person*[_MaxSize];
	_allocated = 1;
	for (int i = 0; i < n; i++)	// makes a copy of the original array.
	{
		_data[i] = new Person(*(arr[i]));
	}

	for (int j = n / 2 - 1; j >= 0; j--)	// floyd algorithm.
		fixHeap(j, numComp);
}
//-----------------------------------------------------------------------------------------------//
Heap::~Heap()
{
	if (_allocated)
	{
		for (int i = 0; i < _heapSize; i++)	// note
		{
			delete _data[i];
		}
		delete[]_data;
	}
	_data = NULL;
}
//-----------------------------------------------------------------------------------------------//
Person* Heap::deleteMin(int& numComp)
{
	if (_heapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}
	Person* min = _data[0];
	_heapSize--;
	_data[0] = _data[_heapSize];
	fixHeap(0, numComp);
	return min;
}
//-----------------------------------------------------------------------------------------------//
Person* Heap::min()
{
	if (_heapSize < 1)
	{
		cout << "Error: EMPTY HEAP\n";
		exit(1);
	}
	return _data[0];
}
//-----------------------------------------------------------------------------------------------//
void Heap::insert(Person* item)
{
	if (_heapSize == _MaxSize)
	{
		cout << "Error: HEAP FULL\n";
		exit(1);
	}
	int i = _heapSize;
	_heapSize++;

	while ((i > 0) && (*(_data[Parent(i)]) > *item))
	{
		_data[i] = _data[Parent(i)];
		i = Parent(i);
	}
	_data[i] = item;
}
//-----------------------------------------------------------------------------------------------//
