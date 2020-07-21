#pragma once
#include <iostream>
using namespace std;
#include "Node.h"

class LinkedList
{
private:
	Node *head, *tail;
	
public:
	LinkedList();
	~LinkedList();
	void MakeEmpty();
	bool isEmpty() const;
	Node* first() const;
	void Append(int item);
};
