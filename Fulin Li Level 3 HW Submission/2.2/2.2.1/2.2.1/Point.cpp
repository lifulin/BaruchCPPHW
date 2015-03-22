// Point.cpp
//
// Header file for Points in two dimensions.
//
// @author Fulin Li
// @version 1.0 11/08/14

#include "Point.hpp"
#include <sstream>
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
