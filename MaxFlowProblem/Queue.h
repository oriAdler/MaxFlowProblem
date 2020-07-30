#pragma once
#include "Node.h"
//this class represent Queue
//with classic Enqueue and Dequeue methods
class Queue
{
private:
	Node *head, *tail;

public:
	Queue();
	~Queue();
	void MakeEmpty();
	int IsEmpty();
	int Front();
	void EnQueue(int item);
	int DeQueue();
};
