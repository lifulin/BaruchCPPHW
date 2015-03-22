// Visitor.hpp
//
// Header file for Visitor class.
//
// @author Fulin Li
// @version 1.0 12/14/14

#ifndef Visitor_HPP
#define Visitor_HPP

#include <boost/variant/static_visitor.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

class Visitor : public boost::static_visitor<void>
{
private:
	double m_dx; // x-coordinate
	double m_dy; // y-coordinate

public:
	// Constructors and destructor
	Visitor(); // Default constructor
	Visitor(const Visitor& source); // Copy constructor
	Visitor(double xValue, double yValue); // Constructor accepting x- and y-coordinates
	~Visitor(); // Destructor

	// Member operator overloading
	Visitor& operator = (const Visitor& source); // Assignment operator
	void operator () (Point& p) const; // () operator for Point
	void operator () (Line& p) const; // () operator for Line
	void operator () (Circle& p) const; // () operator for Circle
};

#endif