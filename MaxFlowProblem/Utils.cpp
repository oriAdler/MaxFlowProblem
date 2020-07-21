﻿#include "Utils.h"

pair<int,int>* Utils::initializeSingleSource(DirectedGraph G, int s, int d[])
{
	int numOfVertex = G.getSize();
	pair<int,int>* arr = new pair<int,int>[numOfVertex];
	// d[s] = 0, ∀ v≠s: d[v] = -∞
	for(int i=0; i< numOfVertex; i++)
	{
		if(i==s)
		{
			d[i] = INT_MAX;	
		}
		else
		{
			d[i] = INT_MIN;
		}
		arr[i] = pair<int,int>(i, d[i]);
	}
	
	return arr;
}

//Returns true if there is a path from source 's' to sink 't' in graph G.
//Also fills parent[] to store the path.
bool Utils::BFSPath(const DirectedGraph& G, int s, int t, int d[], int p[])
{
	Queue Q;
	int size = G.getSize();

	//For each vertex v do d[v] <- Infinity
	for (int i = 0; i < size; i++)
	{
		d[i] = INT_MAX;
	}
	Q.EnQueue(s);
	d[s] = 0;
	p[s] = -1;

	while (!Q.IsEmpty())
	{
		int u = Q.DeQueue();
		LinkedList* adjList = G.GetAdjList(u);
		Node* current = adjList->first();
		//For each v IN Adj[u] do 
		while(current)
		{
			int v = current->data;
			if (d[v] == INT_MAX)
			{
				p[v] = u;
				d[v] = d[u] + 1;
				Q.EnQueue(v);
			}
			current = current->next;
		}
		delete adjList;
	}
	
	return d[t] != INT_MAX ? true : false;
}

// note: explain changes in algorithm - documentation
MinCut* Utils::fordFulkerson(const DirectedGraph& G, int s, int t,
	bool PathFunc(const DirectedGraph& G, int s, int t, int d[], int p[]), int& numOfIterations)
{
	int u, v;
	DirectedGraph Gf(G);	//The residual graph is equal to the original graph
	int* d = new int[G.getSize()];
	int* p = new int[G.getSize()];
	int maxFlow = 0;

	//Find better Path P from 's' to 't' via BFS
	while (PathFunc(Gf, s, t, d, p))
	{
		numOfIterations++;
		//Calculate path's residual flow
		int pathFlow = INT_MAX;
		for (v = t; v != s; v = p[v])
		{
			u = p[v];
			pathFlow = pathFlow < Gf(u, v) ? pathFlow : Gf(u, v);
		}
		//Update capacity on edges along the path of the residual graph
		for (v = t; v != s; v = p[v])
		{
			u = p[v];
			Gf(u, v) -= pathFlow;
			Gf(v, u) += pathFlow;
		}
		//cout << endl;
		//Gf.Show();
		maxFlow += pathFlow;
	}

	MinCut* res = new MinCut(d, G.getSize(), maxFlow, s);
	delete []p;
	delete []d;
	return res;
}

bool Utils::dijkstraVariationPath(const DirectedGraph& G, int s, int t, int d[], int p[])
{
	//Init
	int numOfVertex = G.getSize();
	pair<int, int>* arr = initializeSingleSource(G, s, d);
	PriorityQueue Q(arr, numOfVertex);

	while (!Q.isEmpty())
	{
		int u = Q.deleteMax().first;
		LinkedList* adjList = G.GetAdjList(u);
		Node* current = adjList->first();
		//For each v IN Adj[u] do
		while(current)
		{
			int v = current->data;
			int min = d[u] < G(u, v) ? d[u] : G(u, v);
			if (min > d[v])
			{
				d[v] = min;
				p[v] = u;
				Q.increaseKey(v, d[v]);
			}
			current = current->next;
		}
		delete adjList;
	}

	delete[]arr;
	return d[t] != INT_MIN ? true : false;
}
