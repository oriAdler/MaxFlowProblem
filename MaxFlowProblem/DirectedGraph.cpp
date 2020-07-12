#include "DirectedGraph.h"
#include <cstring>
#include <iostream>
using namespace std;
DirectedGraph::DirectedGraph(int n)
{
	MakeEmptyGraph(n);
}

DirectedGraph::~DirectedGraph()
{
	for (int i = 0; i < _size; i++)
	{
		delete[]_AdjacencyMatrix[i];
	}
	delete[] _AdjacencyMatrix;
	
}

int DirectedGraph::getSize()
{
	return _size;
}

// note: why need?????????????????????????
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
		//memset(_AdjacencyMatrix[i], 0, sizeof(int) * sizeof _size);
	}
}

bool DirectedGraph::IsAdjacent(int u, int v) const
{
	return _AdjacencyMatrix[u][v];
}
//note: what to return?????????????????????????
int* DirectedGraph::GetAdjList(int u) const
{
	int* AdjList = new int[_size];
	memcpy(AdjList, _AdjacencyMatrix[u], sizeof(int));
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

void DirectedGraph::Show()
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			cout << "| " << _AdjacencyMatrix[i][j] << " |";
		}
		cout << endl;
	}
}

void DirectedGraph::Show()
{
	for (int i = 0; i < _size; i++)
	{
		for (int j = 0; j < _size; j++)
		{
			cout << "| " << _AdjacencyMatrix[i][j] << " |";
		}
		cout << endl;
	}
}
