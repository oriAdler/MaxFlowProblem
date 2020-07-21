// ReSharper disable All
#include "Input.h"
#include "DirectedGraph.h"

DirectedGraph *Input::handleInput(int &s, int &t, char *fileName)
{
	string input;
	ifstream inFile(fileName, ios::in);
	if(!inFile.is_open())
	{
		cout << "File is not found";
		exit(1);
	}

	//Get number of vertex, edges, 's' and 't': 
	int numOfVertex = getValidLine(inFile, isInteger, isPositive);	//note: if num of vertex is 0?
	DirectedGraph *newGraph = new DirectedGraph(numOfVertex);

	int numOfEdges = getValidLine(inFile, isInteger, isNonNegative);

	s = getValidLine(inFile, isInteger, inRange, numOfVertex); 
	t = getValidLine(inFile, isInteger, inRange ,numOfVertex);

	//Get edges and capacities: 
	//While not end of file, or there are still remaining edges to receive
	for (int i = 0; i < numOfEdges; i++)
	{
		int trio[3];
		int wordsCounter;
		input = getNextNonEmptyLine(inFile);
		if (countWords(input) != 3 || !isValidTrio(input, trio, numOfVertex))
		{
			invalidInput(inFile);
		}
		//Input is valid store data in graph
		// u <- u-1 , v <- v-1, capacity
		int u = trio[0] - 1, v = trio[1] - 1, capacity = trio[2];
		//Check if edge already exists in current graph (parallel edges)
		if(newGraph->IsAdjacent(u, v))
		{
			invalidInput(inFile);
		}
		newGraph->AddEdge(u, v, capacity);
	}
	//Check there is no garabage data after last edge //note: fix
	while(!inFile.eof())
	{
		if(!getline(inFile, input, '\n') || countWords(input)!=0)
		{
			invalidInput(inFile);
		}
	}
	inFile.close();

	return newGraph;
}

//Checks if both arguments are true, and converts input into int.
int Input::getValidLine(ifstream& inFile, bool arg1(string s), bool arg2(string s))
{
	
	//Expecting to find a valid line with one word represting an integer.
	string input = getNextNonEmptyLine(inFile);
	if (countWords(input)!=1 || !arg1(input) || !arg2(input))
	{
		invalidInput(inFile);
	}
	return stoi(input);
}
//Checks if both arguments are true, and converts input into int.
int Input::getValidLine(ifstream& inFile, bool arg1(string s), bool arg2(string s, int n),int num)
{
	string input = getNextNonEmptyLine(inFile);

	if (countWords(input)!=1 || !arg1(input) || !arg2(input, num))
	{
		invalidInput(inFile);
	}
	return stoi(input);
}
string Input::getNextNonEmptyLine(ifstream& inFile)
{
	string input;
	int wordsCounter;
	//boolean represent valid read from file
	bool validReadFromFile= (!inFile.eof() && getline(inFile, input, '\n'));
	//continue while lines read from file are read successfully and line contains only white spaces.
	while (validReadFromFile && countWords(input) == 0)
	{
		validReadFromFile = (!inFile.eof() && getline(inFile, input, '\n'));
	}
	//check that while was exited because of non zero word count and not becuase of line read failure
	if(!validReadFromFile)
	{
		invalidInput();
	}
	//return relevant input after skipping all empty lines
	return input;
}



bool Input::isInteger(string str)
{
	removeSpaces(str);
	int length = str.length();

	for(int i=0; i<length; i++)
	{
		if(!isDigit(str[i]))
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

void Input::invalidInput()
{
	cout << "Invalid input!" << endl;
	exit(1);
}

bool Input::isNonNegative(string str)
{
	int number = stoi(str);
	return number >= 0;
}

bool Input::isValidTrio(string str, int trio[], int numOfVertex)
{
	stringstream currentLine;
	//Store the whole line into string stream
	currentLine << str;

	//Runing loop till the end of the current line.
	string tempNumber;
	int counter = 0;
	while (!currentLine.eof() && counter < 3)
	{
		//Extracting word by word from stream
		currentLine >> tempNumber;
		if(counter==2)	//Check capacity is valid
		{
			if (!isInteger(tempNumber) && isPositive(tempNumber))
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
			invalidInput();
		}
	}
	return true;
}

bool Input::isDigit(char c)
{
	return c >= '0' && c <= '9';
}

//Returns the number of words in string
int Input::countWords(string str)
{
	int state = OUT;
	int wordCounter = 0;
	int length = str.length();

	//Scan all characters one by one
	for (int i = 0; i < length; i++)
	{
		//If next character is seperator, set the state as OUT
		if (str[i] == ' ' || str[i] == '\t')
		{
			state = OUT;
		}
			//If next character is not a seperator and state is OUT,
			//then set the state IN and increment word count
		else if (state == OUT)
		{
			state = IN;
			wordCounter++;
		}
	}

	return wordCounter;
}

//remove all spaces from a given string
void Input::removeSpaces(string& str)
{
	//To keep track of non-space character count
	int count = 0;
	int length = str.length();

	//Traverse the given string. if current character is not space,
	//then place it at index 'count++'
	for (int i = 0; i < length; i++)
	{
		if (str[i] != ' ')
		{
			str[count++] = str[i];
		}
	}
	str.resize(count);
}
