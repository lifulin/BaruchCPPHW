// TestExceptionObjects.cpp
//
// Test program for out of bound exception objects.
// 
// @author Fulin Li
// @version 1.0 11/15/14

#include "Array.hpp"
#include "ArrayException.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Array array(3);
	
	try
	{
		cout << array[4] << endl;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}
}