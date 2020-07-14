#pragma once

//Directed Graph implemented as Adjacency Matrix.
//The matrix contains the edge's capacity value: A[u][v] = c(u,v).
class DirectedGraph
{
private:
	int** _AdjacencyMatrix;
	int _size;
	
public:
	DirectedGraph(int n);
	~DirectedGraph();
	int getSize() const;
	void MakeEmptyGraph(int n);
	bool IsAdjacent(int u, int v) const;
	int* GetAdjList(int u) const;
	void AddEdge(int u, int v, int capacity) const;
	void RemoveEdge(int u, int v) const;
	void Show() const;
};
