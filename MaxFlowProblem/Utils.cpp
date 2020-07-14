#include "Utils.h"
#include "Queue.h"
#define INFINITY 2147483647

//Returns true if there is a path from source 's' to sink 't' in graph G.
//Also fills parent[] to store the path.
bool Utils::BFSPath(DirectedGraph G, int s, int t, int p[])
{
	Queue Q;
	int size = G.getSize();
	int* d = new int[size];

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
	
	bool res = d[t] != INFINITY ? true : false;
	delete[] d;
	return res;
}