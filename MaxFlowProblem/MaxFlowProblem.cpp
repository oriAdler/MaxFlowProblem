
#include <iostream>
#include "FlowNetwork.h"
#include "Utils.h"
using namespace std;

FlowNetwork* handleInput()
{
	int numOfV, numOfEdges, s, t;
	cin >> numOfV;

	const DirectedGraph newGraph = DirectedGraph(numOfV);
	cin >> numOfEdges;
	cin >> s;
	cin >> t;

	for (int i = 0; i < numOfEdges; i++)
	{
		int u, v, capacity;
		cin >> u >> v >> capacity;
		newGraph.AddEdge(u-1, v-1, capacity);
	}
	// note: start from 
	FlowNetwork* newFlowNetwork = new FlowNetwork(newGraph, s-1, t-1);
	return newFlowNetwork;
}

void printArr(int arr[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout << " " << arr[i] << " " << endl;
	}
}

int main()
{
	FlowNetwork* newFlowNetwork = handleInput();
	newFlowNetwork->getDirectedGraph().Show();
	int* parent = new int[newFlowNetwork->getDirectedGraph().getSize()];
	Utils::BFSPath(newFlowNetwork->getDirectedGraph(), 0, 5, parent);
	printArr(parent, newFlowNetwork->getDirectedGraph().getSize());
	//
	//DirectedGraph G(6);
	//int n;
	//G.Show();
	//cin >> n;
}
