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
//
// @author Fulin Li
// @version 1.5 11/8/14

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

double Point::X() const
{
	return m_x;
}

double Point::Y() const
{
	return m_y;
}

void Point::X(double newX)
{
	m_x = newX;
}

void Point::Y(double newY)
{
	m_y = newY;
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