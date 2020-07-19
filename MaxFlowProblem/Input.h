#pragma once
#include "DirectedGraph.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

class Input
{
public:
	static DirectedGraph* handleInput(int& s, int& t, char* fileName);
	//DirectedGraph* handleInput(int& s, int& t);
private:
	static bool checkInput(const DirectedGraph& G);
	static bool isInteger(string s);
	static void invalidInput();	//note: close the file?
	static bool isNegative(string s);
	static bool isPositive(string s);
	static bool inRange(string s, int n);
	static bool isValidTrio(string s, int trio[]);
};

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
