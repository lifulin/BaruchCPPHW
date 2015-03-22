// TestPoint.cpp
//
// Test program for the Point class.
//
// Last Modifications:
// 2014-11-8 Print the distance between the origin and another point
//
// @author Fulin Li
// @version 1.1 11/08/14

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

	Point point1;

	point1.SetX(x1);
	point1.SetY(y1);

	cout << point1.ToString() << endl;
	cout << point1.GetX() << " " << point1.GetY() << endl;

	// Ask the user for the x- and y-coordinates of point2.
	cout << "Please input x and y of Point2 in the following format:" << endl << "x y" << endl;

	if (!(cin >> x2 >> y2))
	{
		cout << "Input Error." << endl;
		return;
	}

	Point point2;

	point2.SetX(x2);
	point2.SetY(y2);
	
	cout << point2.ToString() << endl;
	cout << point2.GetX() << " " << point2.GetY() << endl;

	// Print the distance between the origin and the first point.
	cout << "The distance between origin and " << point1.ToString() << " is " 
		<< point1.DistanceOrigin() << "." << endl;

	// Print the distance between the first point and the second point.
	cout << "The distance between " << point1.ToString() << " and " << point2.ToString() 
		<< " is " << point1.Distance(point2) << "." << endl;
}