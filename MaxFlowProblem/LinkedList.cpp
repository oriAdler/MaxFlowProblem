#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node;
	tail = head;
}

LinkedList::~LinkedList()
{
	MakeEmpty();
}
//delete all nodes from list
void LinkedList::MakeEmpty()
{
	while (!isEmpty())
	{
		Node *temp = head;
		head = head->next;
		delete temp;
	}
	delete tail;
}

bool LinkedList::isEmpty() const
{
	return head == tail;
}
//this method returns pointer of the element from the head of the list
Node *LinkedList::first() const
{
	if (isEmpty())
	{
		return nullptr;
	}
	return (head->next);
}
//this method appends element to the end of the list
void LinkedList::Append(int item)
{
	Node *newNode = new Node(item);
	tail->InsertAfter(newNode);
	tail = newNode;
}
