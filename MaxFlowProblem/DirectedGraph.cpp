#include "DirectedGraph.h"

//ctor
DirectedGraph::DirectedGraph(int n)
{
	MakeEmptyGraph(n);
}
//copy ctor
DirectedGraph::DirectedGraph(const DirectedGraph &other)
{
	this->MakeEmptyGraph(other._size);
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
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

//Creates a graph with n vertices and no edges.
void DirectedGraph::MakeEmptyGraph(int n)
{
	_size = n;
	_AdjacencyMatrix = new int *[n];
	for (int i = 0; i < _size; i++)
	{
		_AdjacencyMatrix[i] = new int[n];
		for (int j = 0; j < _size; j++)
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
LinkedList *DirectedGraph::GetAdjList(int u) const
{
	LinkedList *AdjList = new LinkedList();
	for (int v = 0; v < _size; v++)
	{
		if (this->IsAdjacent(u, v))
		{
			AdjList->Append(v);
		}
	}
	return AdjList;
}
//updates edge value in adjacency matrix
void DirectedGraph::AddEdge(int u, int v, int capacity) const
{
	_AdjacencyMatrix[u][v] = capacity;
}
//updates edge value in adjacency matrix
void DirectedGraph::RemoveEdge(int u, int v) const
{
	_AdjacencyMatrix[u][v] = 0;
}
//returns _AdjacencyMatrix[u][v] capacity
const int &DirectedGraph::operator()(int x, int y) const
{
	return _AdjacencyMatrix[x][y];
}
//returns _AdjacencyMatrix[u][v] capacity
int &DirectedGraph::operator()(int x, int y)
{
	return _AdjacencyMatrix[x][y];
}
