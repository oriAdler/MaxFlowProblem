#include "Node.h"

Node::Node()
{
	next = nullptr;
}
Node::Node(int item, Node *ptr)
{
	data = item;
	next = ptr;
}


void Node::InsertAfter(Node* newNode)
{
	newNode->next = next;
	next = newNode;
}
Node* Node::DeleteAfter()
{
	Node *temp = next;
	if(!next)
	{
		return nullptr;
	}
	next = temp->next;
	return  temp;
}
