#include "Input.h"
#include "DirectedGraph.h"

DirectedGraph* Input::handleInput(int& s, int& t)
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
		newGraph->AddEdge(u - 1, v - 1, capacity);
	}
	return newGraph;
}

//bool Input::checkInput(const DirectedGraph& G)
//{
//	int size = G.getSize();
//	//check if simple graph
//	for(int i=0; i<size; i++)
//	{
//		if(G(i,i))
//		{
//			return false;
//		}
//	}
//}


//DirectedGraph* Input::handleInput(char* filepath, int& s, int& t)
//{
//	ifstream fio;
//	fio.open(filepath, ios::in);
//	string line;
//	while (fio)
//	{
//		// Read a Line from standard input 
//		getline(cin, line);
//
//		// Press -1 to exit 
//		if (line == "-1")
//			break;
//
//		// Write line in file 
//		fio << line << endl;
//	}
//
//	int numOfV, numOfEdges;
//	cin >> numOfV;
//
//	DirectedGraph* newGraph = new DirectedGraph(numOfV);
//	cin >> numOfEdges;
//	cin >> s;
//	cin >> t;
//
//	for (int i = 0; i < numOfEdges; i++)
//	{
//		int u, v, capacity;
//		cin >> u >> v >> capacity;
//		newGraph->AddEdge(u - 1, v - 1, capacity);
//	}
//}
//
//return newGraph;
//}