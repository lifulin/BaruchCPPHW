// TestPoint.cpp
//
// Test program for the Point class.
//
// @author Fulin Li
// @version 1.0 11/08/14

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	double newX, newY;

	// Ask the user for the x- and y-coordinates.
	cout << "Please input x and y in the following format:" << endl << "x y" << endl;

	if (!(cin >> newX >> newY))
	{
		cout << "Input Error." << endl;
		return;
	}

	// Create a Point object using the default constructor.
	Point point;

	// Set the coordinates entered by the user.
	point.SetX(newX);
	point.SetY(newY);

	// Print the description of the point.
	cout << point.ToString() << endl;

	// Print the point coordinates.
	cout << point.GetX() << " " << point.GetY() << endl;
}