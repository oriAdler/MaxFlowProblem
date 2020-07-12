//-----------------------------------------------------------------------------------------------//
#ifndef __HEAP_H_
#define __HEAP_H_
#include "system.h"
//-----------------------------------------------------------------------------------------------//
class Heap
{
private:
	Person** _data;
	int _MaxSize;
	int _heapSize;
	int _allocated;

	static int Left(int node);
	static int Right(int node);
	static int Parent(int node);
	void fixHeap(int node, int& numComp);

public:
	Heap(int max);
	Heap(Person* arr[], int n, int& numComp);	// question: במקום להעביר פרמטר numcomp משתנה סטטי?
	~Heap();
	Person* min();
	Person* deleteMin(int& numComp);
	void insert(Person* item);

	static Person* selectHeap(Person* arr[], int n, int k, int& numComp);
};
//-----------------------------------------------------------------------------------------------//
#endif //__HEAP_H_
