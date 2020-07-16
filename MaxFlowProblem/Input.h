#pragma once
#include "DirectedGraph.h"
#include <iostream>
using namespace std;

class Input
{
public:
	static DirectedGraph* handleInput(int& s, int& t);
private:
	static bool checkInput(const DirectedGraph& G);
};
