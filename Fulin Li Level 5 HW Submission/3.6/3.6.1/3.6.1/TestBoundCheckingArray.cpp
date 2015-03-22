// TestBoundCheckingArray.cpp
//
// Test program for bound checking array.
// 
// @author Fulin Li
// @version 1.0 11/15/14

#include "Array.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Array array(3);
	//cout << array[4] << endl; // An exception is thrown.

	try
	{
		cout << array[4] << endl;
	}
	catch (int err)
	{
		if (err == -1)
		{
			cout << "Index out of bound." << endl;
		}
	}
}