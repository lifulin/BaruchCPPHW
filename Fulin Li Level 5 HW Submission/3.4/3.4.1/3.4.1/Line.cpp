// Line.cpp
//
// Header file for Lines in two dimensions.
//
// @author Fulin Li
// @version 1.0 11/15/14

#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

// Default constructor without colon syntax.
//Line::Line()
//{
//	p1 = Point(0.0, 0.0);
//	p2 = Point(0.0, 0.0);
//}

// Default constructor with colon syntax.
Line::Line() : p1(0, 0), p2(0, 0)
{
}

// Constructor accepting two points without colon syntax.
//Line::Line(const Point& val1, const Point& val2)
//{
//	p1 = val1;
//	p2 = val2;
//}

// Constructor accepting two points with colon syntax.
Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2)
{
}

// Copy constructor without colon syntax.
//Line::Line(const Line& source)
//{
//	p1 = source.p1;
//	p2 = source.p2;
//}

// Copy constructor with colon syntax.
Line::Line(const Line& source) : p1(source.p1), p2(source.p2)
{
}

Line::~Line()
{
}

Point Line::P1() const
{
	return p1;
}

Point Line::P2() const
{
	return p2;
}

void Line::P1(const Point& newP1)
{
	p1 = newP1;
}

void Line::P2(const Point& newP2)
{
	p2 = newP2;
}

double Line::Length() const
{
	return p1.Distance(p2);
}

string Line::ToString() const
{
	stringstream stream;

	stream << "Line: " << p1.ToString() << "-" << p2.ToString();

	return stream.str();
}

Line& Line::operator = (const Line& source)
{ // Assignment operator.

	if (this == &source)
	{
		return *this;
	}

	p1 = source.p1;
	p2 = source.p2;

	return *this;
}

ostream& operator << (ostream& os, const Line& l)
{ // Send to ostream

	os << "Line: " << l.p1 << "-" << l.p2 << endl;

	return os;
}