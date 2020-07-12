#include "Queue.h"

#include <iostream>
using namespace std;
Queue::Queue()
{
	head = new Node;
	tail = head;
}

Queue::~Queue()
{
	MakeEmpty();
}

void Queue::MakeEmpty()
{
	while(!IsEmpty())
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	
}

int Queue::IsEmpty()
{
	return head == tail;
}

void Queue::EnQueue(int item)
{
	Node *newNode = new Node(item);
	tail->InsertAfter(newNode);
	tail = newNode;
}

int Queue::DeQueue()
{
	if (IsEmpty())
	{
		cout << "Error: QUEUE EMPTY!!" << endl;
		exit(1);
	}
	Node *temp = head->DeleteAfter();
	int item = temp->data;
	if (tail == temp)
	{
		tail = head;
	}
	delete temp;
	return item;
}
