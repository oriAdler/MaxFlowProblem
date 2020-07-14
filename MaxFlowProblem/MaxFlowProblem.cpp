
#include <iostream>
#include "FlowNetwork.h"
#include "Utils.h"
using namespace std;

DirectedGraph* handleInput()
{
	int numOfV, numOfEdges, s, t;
	cin >> numOfV;

	DirectedGraph* newGraph = new DirectedGraph(numOfV);
	cin >> numOfEdges;
	cin >> s;
	cin >> t;

	for (int i = 0; i < numOfEdges; i++)
	{
		int u, v, capacity;
		cin >> u >> v >> capacity;
		newGraph->AddEdge(u-1, v-1, capacity);
	}
	// note: start from 
	//FlowNetwork* newFlowNetwork = new FlowNetwork(newGraph, s-1, t-1);
	return newGraph;
}

//void printArr(int arr[], int size)
//{
//	for(int i=0; i<size; i++)
//	{
//		cout << " " << arr[i] << " " << endl;
//	}
//}

int main()
{
	DirectedGraph* newGraph = handleInput();
	newGraph->Show();
	int numOfIterations = 0;
	MinCut res = Utils::fordFulkerson(*newGraph, 0, 5, numOfIterations);
	res.Show();
	cout << "Number of iteration = " << numOfIterations;
	//int* parent = new int[newGraph->getSize()];
	//Utils::BFSPath(*newGraph, 0, 5, parent);
	//printArr(parent, newFlowNetwork->getDirectedGraph().getSize());
	//
	//DirectedGraph G(6);
	//int n;
	//G.Show();
	//cin >> n;
}
