// Point.cpp
//
// Header file for Points in two dimensions.
// 
// Last Modifications:
// 2014-11-8 Add distance functions
// 2014-11-8 Add copy constructor and a constructor that accepts x- and y-coordinates
// 2014-11-8 Pass by reference in the Distance() function
// 2014-11-8 Rename DistanceOrigin() to Distance(), rename getter and setter functions
// 2014-11-8 Mark X(), Y(), Distance() and ToString() as const
// 2014-11-8 Delete the setter and getter functions
// 2014-11-8 Restore the setter and getter functions, and make them inline functions
// 2014-11-8 Restore the setter and getter functions, and make them inline functions
//
// @author Fulin Li
// @version 1.7 11/8/14

#include "Point.hpp"
#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

Point::Point() // Default constructor
{
	cout << "Default Constructor Called." << endl;
}

Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y) // Copy constructor
{
	cout << "Copy Constructor Called." << endl;
}

Point::Point(double xValue, double yValue) : m_x(xValue), m_y(yValue) // Constructor that accepts x- and y-coordinates
{
	cout << "Constructor Accepting x- and y-coordinates Called." << endl;
}

Point::~Point() // Destructor
{
	cout << "Destructor Called." << endl;
}

string Point::ToString() const
{
	stringstream stream;

	stream << "Point(" << m_x << "," << m_y << ")";

	return stream.str();
}

double Point::Distance() const
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(const Point& p) const
{
	// p.SetX(); // Result in compiler error.
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}