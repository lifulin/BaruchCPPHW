// PointArray.cpp
//
// Header file for PointArray class.
//
// @author Fulin Li
// @version 1.0 12/06/14

#include "PointArray.hpp"
#include "Point.hpp"

// Constructors
PointArray::PointArray() : Array()
{ // Default constructor.
}

PointArray::PointArray(int size) : Array(size)
{
}

PointArray::PointArray(const PointArray& pp) : Array(pp)
{ // Copy constructor.
}

PointArray::~PointArray()
{ // Destructor.
}

PointArray& PointArray::operator = (const PointArray& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Array<Point>::operator = (source);

	return *this;
}

double PointArray::Length() const
{
	double length = 0.0;

	for (int i = 0; i < Array<Point>::Size() - 1; i ++)
	{
		length += (Array<Point>:: operator [] (i)).Distance(Array<Point>:: operator [] (i + 1));
	}

	return length;
}
