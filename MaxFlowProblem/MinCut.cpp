#include "MinCut.h"

//Constructor
// will receive final d array, array size, max flow and source
// finds S,T cuts using the array.
MinCut::MinCut(int arr[], int size, int max, int s)
{
	_maxFlow = max;
	for (int i = 0; i < size; i++)
	{
		//If vertex is source or reachable in Gf
		if (i == s || (arr[i] != INT_MAX && arr[i] != INT_MIN))
		{
			_S.EnQueue(i);
		}
		else
		{
			_T.EnQueue(i);
		}
	}
}
//Prints to console
void MinCut::Show()
{
	cout << "Max flow = " << _maxFlow << endl;
	cout << "Min cut: S = ";
	while (!_S.IsEmpty())
	{
		cout << _S.DeQueue() + 1; //Convert output: u <- u + 1.
		if (!_S.IsEmpty())
		{
			cout << ", ";
		}
	}
	cout << ". T = ";
	while (!_T.IsEmpty())
	{
		cout << _T.DeQueue() + 1;
		if (!_T.IsEmpty())
		{
			cout << ", ";
		}
	}

	cout << "." << endl;
}
