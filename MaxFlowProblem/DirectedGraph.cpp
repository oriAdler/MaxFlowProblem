#include "DirectedGraph.h"
#include <cstring>
#include "Queue.h"
#include <iostream>

#include "LinkedList.h"
using namespace std;

DirectedGraph::DirectedGraph(int n)
{
	MakeEmptyGraph(n);
}

DirectedGraph::DirectedGraph(const DirectedGraph& other)
{
	this->MakeEmptyGraph(other._size);
	for(int i=0; i<_size; i++)
	{
		for(int j=0; j<_size; j++)
		{
			this->_AdjacencyMatrix[i][j] = other._AdjacencyMatrix[i][j];
		}
	}
}

DirectedGraph::~DirectedGraph()
{
	if (_size != 0)	
	{
		for (int i = 0; i < _size; i++)
		{
			delete[] _AdjacencyMatrix[i];
		}
		delete[] _AdjacencyMatrix;
	}
}

int DirectedGraph::getSize() const
{
	return _size;
}

//Creats a graph with n vertices and no edges.
void DirectedGraph::MakeEmptyGraph(int n)
{
	_size = n;
	_AdjacencyMatrix = new int*[n];
	for(int i=0; i< _size ; i++)
	{
		_AdjacencyMatrix[i] = new int[n];
		for(int j=0; j< _size; j++)
		{
			_AdjacencyMatrix[i][j] = 0;
		}
	}
}

bool DirectedGraph::IsAdjacent(int u, int v) const
{
	return _AdjacencyMatrix[u][v];
}

//Returns an adjacency list of u.
//If (u,v) IN E Then (u,v) != 0,
//Else (u,v) = 0.
LinkedList* DirectedGraph::GetAdjList(int u) const
{
	LinkedList* AdjList = new LinkedList();
	for(int v=0; v<_size; v++)
	{
		if(this->IsAdjacent(u,v))
		{
			AdjList->Append(v);
		}
	}
	return AdjList;
}

void DirectedGraph::AddEdge(int u, int v, int capacity) const
{
	_AdjacencyMatrix[u][v] = capacity;
}

void DirectedGraph::RemoveEdge(int u, int v) const
{
	_AdjacencyMatrix[u][v] = 0;
}

void DirectedGraph::Show() const
{
	cout << "  ";
	for (int i = 0; i < _size; i++)
	{
		cout << " | " << i + 1 << " |";
	}
	cout << endl;
	for (int i = 0; i < _size; i++)
	{
		cout << 1 + i << " |";
		for (int j = 0; j < _size; j++)
		{
			cout << "| " << _AdjacencyMatrix[i][j];
			if(_AdjacencyMatrix[i][j] < 10)
			{
				cout << " ";
			}
			cout << " |";
		}
		cout << endl;
	}
}

const int& DirectedGraph::operator()(int x, int y) const
{
	return _AdjacencyMatrix[x][y];
}

int& DirectedGraph::operator()(int x, int y)
{
	return _AdjacencyMatrix[x][y];
}
