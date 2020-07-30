#pragma once
#include "LinkedList.h"
#include <cstring>
#include "Queue.h"
#include <iostream>
using namespace std;
//Directed Graph implemented as Adjacency Matrix.
//The matrix contains the edge's capacity value: A[u][v] = c(u,v).
//As The class uses a matrix which starts at index 0,
//input must be modified, for example u<-u-1.
class DirectedGraph
{
private:
	int **_AdjacencyMatrix;
	int _size;

public:
	DirectedGraph(int n);
	DirectedGraph(const DirectedGraph &other);
	const DirectedGraph &operator=(const DirectedGraph &other) = delete; //avoid shallow copy
	~DirectedGraph();
	int getSize() const;
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v) const;
	LinkedList *GetAdjList(int u) const;
	void AddEdge(int u, int v, int capacity) const;
	void RemoveEdge(int u, int v) const;
	const int &operator()(int x, int y) const;
	int &operator()(int x, int y);
};
