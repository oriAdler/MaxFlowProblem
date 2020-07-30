#pragma once
#include <iostream>
#include "Queue.h"
#include <limits>
using namespace  std;

// The following class represents a Min Cut - Max Flow.
// Contains S,T vertex groups and max flow value.
class MinCutMaxFlow
{
public:
	MinCutMaxFlow(int arr[], int size, int max, int s);
	void Show();
private:
	Queue _S, _T;
	int _maxFlow;
};
