#include "FlowNetwork.h"

FlowNetwork::FlowNetwork(const DirectedGraph& G, int s, int t)
{
	_G = DirectedGraph(G);
	_s = s;
	_t = t;
	_curFlow = 0;
}
