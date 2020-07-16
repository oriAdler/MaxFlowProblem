#pragma once
#include <iostream>
#include "Queue.h"
#include <limits>
using namespace  std;

class MinCut
{
public:
	MinCut(int arr[], int size, int max, int s);
	void Show();
private:
	Queue _S, _T;
	int _maxFlow;
};
