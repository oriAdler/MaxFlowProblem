// ReSharper disable All
#pragma once
#include "DirectedGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#define OUT 0
#define IN 1

class Input
{
public:
	static DirectedGraph *handleInput(int &s, int &t, char *fileName);
private:
	static bool checkInput(const DirectedGraph &G);
	static bool isInteger(string str);
	static void invalidInput(ifstream& inFile); 
	static bool isNonNegative(string str);
	static bool isPositive(string s);
	static bool inRange(string s, int n);
	static bool isValidTrio(string str, int trio[], int numOfVertex);
	static int getValidLine(ifstream& inFile, bool arg1(string s), bool arg2(string s));
	static int getValidLine(ifstream& inFile, bool arg1(string s), bool arg2(string s, int n), int num);
	static bool checkValidGraph(const DirectedGraph& G);
	static void invalidGraph();
	static bool isDigit(char c);
	static int countWords(string str);
	static void removeSpaces(string& str);
};

inline void Input::invalidGraph()
{
	cout << "Invalid Graph" << endl;
	exit(1);
}

inline bool Input::inRange(string s, int n)
{
	int number = stoi(s);
	return number >= 1 && number <= n;
}

inline bool Input::isPositive(string s)
{
	int number = stoi(s);
	return number > 0;
}
