// ReSharper disable All
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
		if (!getline(inFile, input, '\n') || !isValidTrio(input, trio, numOfVertex))
		{
			invalidInput(inFile);
		}
		else
		{
			// u <- u-1 , v <- v-1, capacity
			int u = trio[0] - 1, v = trio[1] - 1, capacity = trio[2];
			//Check if edge already exists in current graph (parllel edges)
			if(newGraph->IsAdjacent(u, v))
			{
				inFile.close();
				invalidGraph();
			}
			newGraph->AddEdge(u, v, capacity);
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
	//note: check that there si only one number
	//Checks if all characters are digits
	for (int i = 0; i < s.length(); i++)
	{
		//skip whitespaces
		if(isspace(s[i]))
		{
			continue;
		}
		//check if digit
		if (!isDigit(s[i]))
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

bool Input::isValidTrio(string s, int trio[], int numOfVertex)
{
	stringstream currentLine;
	//Store the whole line into string stream
	currentLine << s;

	//Runing loop till the end of the current line.
	string tempNumber;
	int counter = 0;
	while (!currentLine.eof() && counter < 3)
	{
		//Extracting word by word from stream
		currentLine >> tempNumber;
		if(counter==2)	//Check capacity is valid
		{
			if (!isInteger(tempNumber) && isNonNegative(tempNumber))
			{
				return false;
			}
		}
		else	//Check is vertex is valid
		{
			if (!isInteger(tempNumber) && inRange(tempNumber, numOfVertex))
			{
				return false;
			}
		}
		trio[counter++] = stoi(tempNumber);
	}
	return counter == 3 ? true : false;
}

bool Input::checkValidGraph(const DirectedGraph &G)
{
	int size = G.getSize();
	//Checks if self loop
	for(int i=0; i<size; i++)
	{
		if (G(i,i)!=0)
		{
			invalidGraph();
		}
	}
	return true;
}

bool Input::isDigit(char c)
{
	return c >= '0' && c <= '9';
}
