#pragma once
#include "DirectedGraph.h"

class FlowNetwork
{
private:
	DirectedGraph _G;
	int _s;
	int _t;
	int _curFlow;
	
public:
	FlowNetwork(const DirectedGraph& G, int s, int t);
	const DirectedGraph& getDirectedGraph() const { return _G; }
};
