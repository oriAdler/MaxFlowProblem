
#include <iostream>
#include "Utils.h"
using namespace std;
#include "Input.h"

/*Program Instructions:
 * 1. Main function gets file's path as argument (proper file path must be sent).
 * 2. Function "handleInput" opens the file, parses the input and checks validation.
 *	  Afterwords generates and returns a directed graph.
 * 3. Function "fordFulkerson" finds MinCutMaxFlow-MaxFlow via BFSPath function using a queue.
 * 4. Function "fordFulkerson" finds MinCutMaxFlow-MaxFlow via a greedy algorithm function "dijkstraVariationPath"
 *	  using a priority queue.
 */

int main(int argc, char *argv[])
{
	//-------------------------------------------------------------------
	// Handle input:
	int s, t;
	DirectedGraph *newGraph = Input::handleInput(s, t, argv[1]);
	cout << endl;
	int numOfIterations = 0;

	//-------------------------------------------------------------------
	// Ford Fulkerson with BFS
	MinCutMaxFlow *res = Utils::fordFulkerson(*newGraph, s - 1, t - 1, Utils::BFSPath, numOfIterations);
	cout << "BFS Method:" << endl;
	res->Show();
	cout << "Number of iterations = " << numOfIterations << endl;
	cout << endl;
	delete res;

	//-------------------------------------------------------------------

	numOfIterations = 0;
	// Ford Fulkerson with Dijkstra variation (Greedy Algorithm)
	res = Utils::fordFulkerson(*newGraph, s - 1, t - 1, Utils::dijkstraVariationPath, numOfIterations);
	cout << "Greedy Algorithm Method:" << endl;
	res->Show();
	cout << "Number of iterations = " << numOfIterations << endl;

	//-------------------------------------------------------------------
	//	Release allocated memory
	delete res;
	delete newGraph;

	//-------------------------------------------------------------------
}
