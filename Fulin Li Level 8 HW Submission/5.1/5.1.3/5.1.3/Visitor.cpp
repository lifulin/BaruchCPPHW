// Visitor.cpp
//
// Header file for Visitor class.
//
// @author Fulin Li
// @version 1.0 12/14/14

#include "Visitor.hpp"

Visitor::Visitor() : boost::static_visitor<void>()
{ // Default constructor
	m_dx = 0.0;
	m_dy = 0.0;
}

Visitor::Visitor(const Visitor& source) : boost::static_visitor<void>(source)
{ // Copy constructor
	m_dx = source.m_dx;
	m_dy = source.m_dy;
}

Visitor::Visitor(double xValue, double yValue) : boost::static_visitor<void>()
{ // Constructor accepting x- and y-coordinates
	m_dx = xValue;
	m_dy = yValue;
}

Visitor::~Visitor()
{ // Destructor
}

Visitor& Visitor::operator = (const Visitor& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Visitor::operator = (source);

	// Copy state
	m_dx = source.m_dx;
	m_dy = source.m_dy;

	return *this;
}

void Visitor::operator () (Point& p) const
{ // () operator for Point

	p.X(p.X() + m_dx);
	p.Y(p.Y() + m_dy);
}

void Visitor::operator () (Line& l) const
{ // () operator for Line

	Point p1 = l.P1();
	Point p2 = l.P2();
	p1.X(p1.X() + m_dx);
	p1.Y(p1.Y() + m_dy);
	p2.X(p2.X() + m_dx);
	p2.Y(p2.Y() + m_dy);

	l.P1(p1);
	l.P2(p2);
}

void Visitor::operator () (Circle& c) const
{ // () operator for Circle

	Point center = c.CentrePoint();
	center.X(center.X() + m_dx);
	center.Y(center.Y() + m_dy);

	c.CentrePoint(center);
}