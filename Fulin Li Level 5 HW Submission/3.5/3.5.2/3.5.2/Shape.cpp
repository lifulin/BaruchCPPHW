// Shape.cpp
//
// Base class for Shapes.
//
// Last Modifications:
// 2014-11-15 Declare the ToString() function as virtual
//
// @author Fulin Li
// @version 1.1 11/15/14

#include "Shape.hpp"
#include <stdlib.h>
#include <sstream>

// Constructors and destructor
Shape::Shape() : m_id(rand())
{ // Default constructor
}

Shape::Shape(const Shape& source) : m_id(source.m_id)
{ // Copy constructor
}

Shape::~Shape()
{ // Destructor
}

// Operator overloading
Shape& Shape::operator = (const Shape& source)
{// Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_id = source.m_id;

	return *this;
}

string Shape::ToString() const
{
	stringstream stream;

	stream << "ID: " << m_id;

	return stream.str();
}

// Accessing functions
int Shape::ID() const
{
	return m_id;
}