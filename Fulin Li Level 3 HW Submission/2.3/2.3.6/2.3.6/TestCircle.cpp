// TestCircle.cpp
//
// Test program for the Circle class.
//
// @author Fulin Li
// @version 1.0 11/08/14

#include "Circle.hpp"
#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	double x, y;
	double r;

	// Ask the user for the x- and y-coordinates of the center.
	cout << "Please input x and y of the center in the following format:"
		<< endl << "x y" << endl;

	if (!(cin >> x >> y))
	{
		cout << "Input Error." << endl;
		return;
	}

	// Ask the user for the radius.
	cout << "Please input radius" << endl;

	if (!(cin >> r))
	{
		cout << "Input Error." << endl;
		return;
	}

	// Create center object.
	Point p_center(x, y);

	// Create circle object.
	Circle circle(p_center, r);

	cout << circle.ToString() << endl;
	cout << "Diameter: " << circle.Diameter() << endl;
	cout << "Area: " << circle.Area() << endl;
	cout << "Circumference: " << circle.Circumference() << endl;
}
