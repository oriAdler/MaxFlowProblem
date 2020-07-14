
#pragma once
#include "DirectedGraph.h"
#include "MinCut.h"
#include "Queue.h"
#define INFINITY 2147483647

class Utils
{
public:
	static bool BFSPath(const DirectedGraph& G, int s, int t, int p[], int d[]);
	static const MinCut& fordFulkerson(const DirectedGraph& G, int s, int t, int& numOfIterations);
};
