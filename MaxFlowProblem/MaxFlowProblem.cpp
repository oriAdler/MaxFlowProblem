
#include <iostream>
#include "PriorityQueue.h"
#include "Utils.h"
using namespace std;

#define _CRTDBG_MAP_ALLOC	//note: check memory leak
#include <stdlib.h>
#include <crtdbg.h>

DirectedGraph* handleInput(int& s, int& t)
{
	int numOfV, numOfEdges;
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
	return newGraph;
}

//void printArr(int arr[], int size)
//{
//	for(int i=0; i<size; i++)
//	{
//		cout << " " << arr[i] << " " << endl;
//	}
//}

int main(int argc, char* argv[])
{
	cout << argc<<endl<<argv[0];

	
	int s, t;
	DirectedGraph* newGraph = handleInput(s, t);
	/*newGraph->Show();*/
	cout << endl;
	int numOfIterations = 0;
	
	MinCut* res = Utils::fordFulkerson(*newGraph, s-1, t-1, Utils::BFSPath, numOfIterations);
	cout << "BFS Method:" << endl;
	res->Show();
	cout << "Number of iterations = " << numOfIterations << endl;
	delete res;

	//-------------------------------------------------------------------
	
	numOfIterations = 0;

	cout << endl;
	res = Utils::fordFulkerson(*newGraph, s-1, t-1, Utils::dijkstraVariationPath, numOfIterations);
	cout << "Greedy Algorithm Method:" << endl;
	res->Show();
	cout << "Number of iterations = " << numOfIterations << endl;

	delete res;
	delete newGraph;

	cout << endl;
	cout << _CrtDumpMemoryLeaks();

	//-------------------------------------------------------------------
}
