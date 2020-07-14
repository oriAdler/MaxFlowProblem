#include "Utils.h"

//Returns true if there is a path from source 's' to sink 't' in graph G.
//Also fills parent[] to store the path.
bool Utils::BFSPath(const DirectedGraph& G, int s, int t, int p[], int d[])
{
	Queue Q;
	int size = G.getSize();

	//For each vertex v do d[v]<-infinity
	for (int i = 0; i < size; i++)
	{
		d[i] = INFINITY;
	}
	Q.EnQueue(s);
	d[s] = 0;
	p[s] = -1;

	while (!Q.IsEmpty())
	{
		int u = Q.DeQueue();

		//For each v IN Adj[u] do
		for (int v = 0; v < size; v++)
		{
			if (G.IsAdjacent(u, v))
			{
				if (d[v] == INFINITY)
				{
					p[v] = u;
					d[v] = d[u] + 1;
					Q.EnQueue(v);
				}
			}
		}
	}
	
	return d[t]!=INFINITY ? true: false;
}

// note: explain changes in algorithm
const MinCut& Utils::fordFulkerson(const DirectedGraph& G, int s, int t, int& numOfIterations)
{
	bool pathExist = true;
	int u, v;
	DirectedGraph Gf(G);	//The residual graph is equal to the original graph
	int* parent = new int[G.getSize()];
	int* d = new int[G.getSize()];
	int maxFlow = 0;

	//Find better Path P from 's' to 't' via BFS
	while (BFSPath(Gf, s, t, parent, d))
	{
		numOfIterations++;	// note: no path at first iteration
		//Calculate path's residual flow
		int pathFlow = INFINITY;
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			pathFlow = pathFlow < Gf(u, v) ? pathFlow : Gf(u, v);
		}
		//Update capacity on edges along the path of the residual graph
		for (v = t; v != s; v = parent[v])
		{
			u = parent[v];
			Gf(u, v) -= pathFlow;
			Gf(v, u) += pathFlow;
		}
		maxFlow += pathFlow;
	}

	MinCut* res = new MinCut(d, G.getSize(), maxFlow);
	return *res;
}
