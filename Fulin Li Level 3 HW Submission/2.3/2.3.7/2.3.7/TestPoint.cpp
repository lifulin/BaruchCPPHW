// TestPoint.cpp
//
// Test program for the Point class.
//
// Last Modifications:
// 2014-11-8 Print the distance between the origin and another point
// 2014-11-8 Print the distance between two points using the constructor that accepts x- and y-coordinates
// 2014-11-8 Create a const point and print its x-coordinate
//
// @author Fulin Li
// @version 1.5 11/08/14

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	double x1, y1;
	double x2, y2;

	// Ask the user for the x- and y-coordinates of point1.
	cout << "Please input x and y of Point1 in the following format:" << endl << "x y" << endl;

	if (!(cin >> x1 >> y1))
	{
		cout << "Input Error." << endl;
		return;
	}

	Point point1(x1, y1);

	cout << point1.ToString() << endl;
	cout << point1.X() << " " << point1.Y() << endl;

	// Ask the user for the x- and y-coordinates of point2.
	cout << "Please input x and y of Point2 in the following format:" << endl << "x y" << endl;

	if (!(cin >> x2 >> y2))
	{
		cout << "Input Error." << endl;
		return;
	}

	Point point2(x2, y2);

	cout << point2.ToString() << endl;
	cout << point2.X() << " " << point2.Y() << endl;

	// Print the distance between the origin and the first point.
	cout << "The distance between origin and " << point1.ToString() << " is " 
		<< point1.Distance() << "." << endl;

	// Print the distance between the first point and the second point.
	cout << "The distance between " << point1.ToString() << " and " << point2.ToString() 
		<< " is " << point1.Distance(point2) << "." << endl;

	const Point cp(1.5, 3.9);
	//cp.X(0.3); // Result in complier error.
	cout << cp.X() << endl;
}