
#pragma once
#include "DirectedGraph.h"
#include "MinCut.h"
#include "Queue.h"
#include "PriorityQueue.h"

class Utils
{
private:
	static Pair* initializeSingleSource(DirectedGraph G, int s, int d[]);
public:
	static bool BFSPath(const DirectedGraph& G, int s, int t, int d[], int p[]);
	static MinCut* fordFulkerson(const DirectedGraph& G, int s, int t, 
		bool PathFunc(const DirectedGraph& G, int s, int t, int d[], int p[]), int& numOfIterations);
	static bool dijkstraVariationPath(const DirectedGraph& G, int s, int t, int d[], int p[]);
};
