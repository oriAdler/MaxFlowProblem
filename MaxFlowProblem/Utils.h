
#pragma once
#include "DirectedGraph.h"
#include "MinCutMaxFlow.h"
#include "Queue.h"
#include "PriorityQueue.h"

// this class wil handle:
// 1. file opening and closing
// 2. input parsing
// 3. input validation
// 4. creating valid directedGraph

// also contains path calculations functions: BFS and dijksta variation path
// and Ford Fulkerson implementation

class Utils
{
private:
	static pair<int, int> *initializeSingleSource(DirectedGraph G, int s, int d[]);

public:
	static bool BFSPath(const DirectedGraph &G, int s, int t, int d[], int p[]);
	static MinCutMaxFlow *fordFulkerson(const DirectedGraph &G, int s, int t,
								 bool PathFunc(const DirectedGraph &G, int s, int t, int d[], int p[]), int &numOfIterations);
	static bool dijkstraVariationPath(const DirectedGraph &G, int s, int t, int d[], int p[]);
};
