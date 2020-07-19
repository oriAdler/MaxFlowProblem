#include "Input.h"
#include "DirectedGraph.h"

DirectedGraph *Input::handleInput(int &s, int &t, char *fileName)
{
	string input;
	ifstream inFile(fileName, ios::in);

	getline(inFile, input, '\n'); //note: line 9 - 14 -> private function?
	int numOfVertex = isValid(input, !isInteger(input), isPositive(input));
	//if num of vertex is 0?

	DirectedGraph *newGraph = new DirectedGraph(numOfVertex);

	getline(inFile, input, '\n');
	int numOfEdges = isValid(input, !isInteger(input), !isNegative(input));

	getline(inFile, input, '\n');
	s = isValid(input, !isInteger(input), !inRange(input, numOfVertex)); //note: check that 's' and 't' each one in separate line

	getline(inFile, input, '\n');
	t = isValid(input, !isInteger(input), !inRange(input, numOfVertex));

	//While not end of file, or there are still remaining edges to receive
	for (int i = 0; i < numOfEdges; i++)
	{
		int trio[3];
		inFile >> input;
		if (!isValidTrio(input, trio))
		{
			invalidInput();
		}
		else
		{
			// u<-u-1 , v <- v-1, capacity
			newGraph->AddEdge(trio[0] - 1, trio[1] - 1, trio[2]);
		}
	}
	return newGraph;

	inFile.close();
}
int Input::isValid(string input, bool arg1, bool arg2)
{
	if (!(arg1 && arg2))
	{
		invalidInput();
	}
	return stoi(input);
}
bool Input::isInteger(string s)
{
	//Checks if all characters are digits
	for (int i = 0; i < s.length(); i++)
	{
		if (isdigit(s[i] == false))
		{
			return false;
		}
	}
	return true;
}

void Input::invalidInput()
{
	cout << "Invalid input!" << endl;
	exit(1);
}

bool Input::isNegative(string s)
{
	int number = stoi(s);
	return number < 0;
}

bool Input::isValidTrio(string s, int trio[])
{
	stringstream currentLine;
	//Store the whole line into string stream
	currentLine << s;

	//Runing loop till the end of the current line.
	string temp;
	int counter = 0;
	while (!currentLine.eof() && counter < 3)
	{
		//Extracting word by word from stream
		currentLine >> temp;
		if (!isInteger(temp))
		{
			return false;
		}
		else
		{
			trio[counter++] = stoi(temp);
		}
	}
	return counter == 3 ? true : false;
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