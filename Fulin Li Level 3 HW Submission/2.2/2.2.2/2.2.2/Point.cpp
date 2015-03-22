// Point.cpp
//
// Header file for Points in two dimensions.
// 
// Last Modifications:
// 2014-11-8 Add distance functions
//
// @author Fulin Li
// @version 1.1 11/8/14

#include "Point.hpp"
#include <sstream>
#include <cmath>
using namespace std;

Point::Point() // Default constructor
{
}

Point::~Point() // Destructor
{
}

double Point::GetX()
{
	return m_x;
}

double Point::GetY()
{
	return m_y;
}

void Point::SetX(double newX)
{
	m_x = newX;
}

void Point::SetY(double newY)
{
	m_y = newY;
}

string Point::ToString()
{
	stringstream stream;

	stream << "Point(" << m_x << "," << m_y << ")";

	return stream.str();
}

double Point::DistanceOrigin()
{
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

double Point::Distance(Point p)
{
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}
