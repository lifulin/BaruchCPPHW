// Circle.cpp
//
// Header file for Circles in two dimensions.
//
// Last Modifications:
// 2014-11-15 Call the ToString() method of the Shape base class in the ToString() method of the derived class
//
// @author Fulin Li
// @version 1.2 11/15/14

#include "Circle.hpp"
#include "Point.hpp"
#include <sstream>

// Constructors and destructor
Circle::Circle() : Shape()
{ // Default constructor
	p_center = Point(0.0, 0.0);
	m_radius = 1.0;
}

Circle::Circle(const Circle& source) : Shape(source)
{ // Copy constructor
	p_center = source.p_center;
	m_radius = source.m_radius;
}

Circle::Circle(const Point& center, double r) : Shape()
{ // Constructor accepting center and radius
	p_center = center;
	m_radius = r;
}

Circle::~Circle()
{ // Destructor
}

Circle& Circle::operator = (const Circle& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Shape::operator = (source);

	// Copy state
	p_center = source.p_center;
	m_radius = source.m_radius;

	return *this;
}

ostream& operator << (ostream& os, const Circle& c)
{ // Send to ostream

	os << "Center: " << c.p_center << ", Radius: " << c.m_radius;

	return os;
}

string Circle::ToString() const
{
	stringstream stream;
	std::string s = Shape::ToString();

	stream << "Center: " << p_center.ToString() << ", Radius: " << m_radius << ", " << s;

	return stream.str();
}