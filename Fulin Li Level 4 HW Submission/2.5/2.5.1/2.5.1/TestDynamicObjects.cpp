// TestDynamicObjects.cpp
//
// Test program for dynamically created objects.
// 
// @author Fulin Li
// @version 1.0 11/9/14

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Point* p1 = new Point();
	Point* p2 = new Point(1, 1);
	Point* p3 = new Point(*p2);

	cout << *p1 << ", " << *p2 << ", " << *p3 << endl;

	cout << "The distance between " << *p3 << " and " << *p1
		<< " is " << (*p3).Distance(*p1) << endl;
	
	delete p1;
	delete p2;
	delete p3;

	cout << "Please input the size of the pointer array." << endl;

	int size;

	if (!(cin >> size))
	{
		cout << "Input Error." << endl;
		return;
	}

	//Point pp[size]; // Compiler error.

	Point* pp = new Point[size]; // Cannot use other constructor.
	delete[] pp;
}