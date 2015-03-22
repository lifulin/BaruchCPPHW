// Circle.cpp
//
// Header file for Circles in two dimensions.
// 
// Last Modifications:
// 2014-11-9 Add assignment operator
//
// @author Fulin Li
// @version 2.0 11/9/14

#define _USE_MATH_DEFINES
#include <cmath>
#include "Circle.hpp"
#include "Point.hpp"
#include <sstream>

Circle::Circle()
{
}

Circle::Circle(const Point& center, double r) : p_center(center), m_radius(r)
{
}

Circle::Circle(const Circle& circle) : p_center(circle.p_center), m_radius(circle.m_radius)
{
}

Circle::~Circle()
{
}

Point Circle::CentrePoint() const
{
	return p_center;
}

double Circle::Radius() const
{
	return m_radius;
}

void Circle::CentrePoint(const Point& newCenter)
{
	p_center = newCenter;
}

void Circle::Radius(double newR)
{
	m_radius = newR;
}

double Circle::Diameter() const
{
	return 2.0 * m_radius;
}

double Circle::Area() const
{
	return M_PI * pow(m_radius, 2);
}

double Circle::Circumference() const
{
	return 2.0 * M_PI * m_radius;
}

string Circle::ToString() const
{
	stringstream stream;

	stream << "Center: " << p_center.ToString() << endl << "Radius: " << m_radius;

	return stream.str();
}

Circle& Circle::operator = (const Circle& source)
{ // Assignment operator

	if (this == &source)
	{
		return *this;
	}

	p_center = source.p_center;
	m_radius = source.m_radius;

	return *this;
}