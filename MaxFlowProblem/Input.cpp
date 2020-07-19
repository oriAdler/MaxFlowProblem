#include "Input.h"
#include "DirectedGraph.h"

DirectedGraph *Input::handleInput(int &s, int &t, char *fileName)
{
	string input;
	ifstream inFile("buggyInput.txt", ios::in);
	if(!inFile.is_open())
	{
		cout << "File is not found";
		exit(1);
	}
	
	int numOfVertex = getValidLine(inFile, isInteger, isPositive);	//note: if num of vertex is 0?
	DirectedGraph *newGraph = new DirectedGraph(numOfVertex);

	int numOfEdges = getValidLine(inFile, isInteger, isNonNegative);

	s = getValidLine(inFile, isInteger, inRange, numOfVertex); //note: check that 's' and 't' each one in separate line
	t = getValidLine(inFile, isInteger, inRange ,numOfVertex);

	//While not end of file, or there are still remaining edges to receive
	for (int i = 0; i < numOfEdges; i++)
	{
		int trio[3];
		//Checks if arrived at end of file, and if current line contains a valid trio.
		if (!getline(inFile, input, '\n') || !isValidTrio(input, trio))
		{
			invalidInput(inFile);
		}
		else
		{
			// u <- u-1 , v <- v-1, capacity
			newGraph->AddEdge(trio[0] - 1, trio[1] - 1, trio[2]);
		}
	}
	////There is more data but 'm' is too small	//note: garbage data at end of file
	//if(!inFile.eof())
	//{
	//	invalidInput();
	//}
	inFile.close();

	return newGraph;
}

//Checks if both arguments are true, and converts input into int.
int Input::getValidLine(ifstream& inFile, bool arg1(string s), bool arg2(string s))
{
	string input;
	if (!getline(inFile, input, '\n'))
	{
		invalidInput(inFile);
	}
	if (!(arg1(input) && arg2(input)))
	{
		invalidInput(inFile);
	}
	return stoi(input);
}
//Checks if both arguments are true, and converts input into int.
int Input::getValidLine(ifstream& inFile, bool arg1(string s), bool arg2(string s, int n),int num)
{
	string input;
	if (!getline(inFile, input, '\n'))
	{
		invalidInput(inFile);
	}
	if (!(arg1(input) && arg2(input, num)))
	{
		invalidInput(inFile);
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

void Input::invalidInput(ifstream& inFile)
{
	inFile.close();
	cout << "Invalid input!" << endl;
	exit(1);
}

bool Input::isNonNegative(string s)
{
	int number = stoi(s);
	return number >= 0;
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