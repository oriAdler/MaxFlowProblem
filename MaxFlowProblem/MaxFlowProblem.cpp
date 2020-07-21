
#include <iostream>
#include "Utils.h"
using namespace std;
#include "Input.h"

#define _CRTDBG_MAP_ALLOC //note: check memory leak
// #include <crtdbg.h>

//void printArr(int arr[], int size)
//{
//	for(int i=0; i<size; i++)
//	{
//		cout << " " << arr[i] << " " << endl;
//	}
//}

int main(int argc, char *argv[])
{

	int s, t;
	DirectedGraph *newGraph = Input::handleInput(s, t, argv[1]);
	/*newGraph->Show();*/
	cout << endl;
	int numOfIterations = 0;

	MinCut *res = Utils::fordFulkerson(*newGraph, s - 1, t - 1, Utils::BFSPath, numOfIterations);
	cout << "BFS Method:" << endl;
	res->Show();
	cout << "Number of iterations = " << numOfIterations << endl;
	delete res;

	//-------------------------------------------------------------------

	numOfIterations = 0;

	cout << endl;
	res = Utils::fordFulkerson(*newGraph, s - 1, t - 1, Utils::dijkstraVariationPath, numOfIterations);
	cout << "Greedy Algorithm Method:" << endl;
	res->Show();
	cout << "Number of iterations = " << numOfIterations << endl;

	delete res;
	delete newGraph;

	cout << endl;
	cout << _CrtDumpMemoryLeaks();

	//-------------------------------------------------------------------
}
