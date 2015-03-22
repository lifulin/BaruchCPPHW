// TestLine.cpp
//
// Test program for the Line class.
//
// @author Fulin Li
// @version 1.0 11/08/14

#include "Line.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	double x1, y1;
	double x2, y2;

	// Ask the user for the x- and y-coordinates of the start point.
	cout << "Please input x and y of the start point in the following format:" 
		<< endl << "x y" << endl;

	if (!(cin >> x1 >> y1))
	{
		cout << "Input Error." << endl;
		return;
	}

	// Ask the user for the x- and y-coordinates of the end point.
	cout << "Please input x and y of the end point in the following format:" 
		<< endl << "x y" << endl;

	if (!(cin >> x2 >> y2))
	{
		cout << "Input Error." << endl;
		return;
	}

	// Create the start point and end point.
	const Point p1(x1, y1);
	const Point p2(x2, y2);

	// Create the line object.
	Line line(p1, p2);

	cout << line.ToString() << ", " << "the length is " << line.Length() << "." << endl;	
}
