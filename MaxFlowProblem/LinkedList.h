#pragma once
#include <iostream>
using namespace std;
#include "Node.h"

//The class implements linked list
// holds dummy head at head of list
class LinkedList
{
private:
	Node *head, *tail;

public:
	LinkedList();
	~LinkedList();
	void MakeEmpty();
	bool isEmpty() const;
	Node *first() const;
	void Append(int item);
};
