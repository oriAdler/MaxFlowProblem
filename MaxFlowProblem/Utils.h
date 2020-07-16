
#pragma once
#include "DirectedGraph.h"
#include "MinCut.h"
#include "Queue.h"

class Utils
{
public:
	static bool BFSPath(const DirectedGraph& G, int s, int t, int p[], int d[]);
	//update: return value in order to delete MinCut in main
	static MinCut* fordFulkerson(const DirectedGraph& G, int s, int t, int& numOfIterations);
};
