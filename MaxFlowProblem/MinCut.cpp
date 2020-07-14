#include "MinCut.h"


MinCut::MinCut(int* arr, int size, int max)
{
	_maxFlow = max;
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != INT_MAX)
		{
			_S.EnQueue(i);
		}
		else
		{
			_T.EnQueue(i);
		}
	}
}

void MinCut::Show()
{
	cout << "Max flow = " << _maxFlow << endl;
	cout << "Min cut: S = ";
	while (!_S.IsEmpty())
	{
		cout << _S.DeQueue() + 1;	//Convert output: u <- u+1.
		if(!_S.IsEmpty())
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
