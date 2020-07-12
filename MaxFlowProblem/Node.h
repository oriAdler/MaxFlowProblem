#pragma once

class Node
{
public:
	int data;
	Node* next;
	Node();
	Node(int item, Node *ptr = nullptr);
	~Node() = default;
	void InsertAfter(Node* newNode);
	Node *DeleteAfter();
};
