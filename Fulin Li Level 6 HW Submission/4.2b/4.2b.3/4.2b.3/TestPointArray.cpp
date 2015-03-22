// TestPointArray.cpp
//
// Test program for PointArray class.
//
// @author Fulin Li
// @version 1.0 12/06/14

#include "PointArray.hpp"
#include <iostream>
using namespace std;

void main()
{
	// Test constructors.
	PointArray pa0;
	cout << "PointArray0: " << endl << "size = " << pa0.Size() << endl;
	
	PointArray pa1(10);
	cout << "PointArray1: " << endl;
	for (int i = 0; i < pa1.Size(); i++)
	{
		pa1[i] = Point(i, i + 1);
		cout << pa1[i] << endl;
	}

	PointArray pa2(pa1);
	cout << "PointArray2: " << endl;
	for (int i = 0; i < pa2.Size(); i++)
	{
		cout << pa2[i] << endl;
	}

	// Test assignment operator.
	PointArray pa3 = pa1;
	cout << "PointArray3: " << endl;
	for (int i = 0; i < pa3.Size(); i++)
	{
		cout << pa3[i] << endl;
	}

	// Test Length() function.
	cout << "Length of PointArray1 = " << pa1.Length() << endl;
}