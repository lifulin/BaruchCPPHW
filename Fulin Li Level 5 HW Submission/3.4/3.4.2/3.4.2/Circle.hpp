// Circle.hpp
//
// Header file for Circles in two dimensions.
//
// @author Fulin Li
// @version 1.1 11/15/14

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
using namespace std;

class Circle : public Shape
{
private:
	Point p_center; // Center
	double m_radius; // Radius

public:
	// Constructors and destructor
	Circle(); // Default constructor
	Circle(const Circle& source); // Copy constructor
	Circle(const Point& center, double r); // Constructor accepting center and radius
	virtual ~Circle(); // Destructor

	// Member operator overloading
	Circle& operator = (const Circle& source); // Assignment operator

	// Global operator overloading
	friend ostream& operator << (ostream& os, const Circle& c); // Send to ostream

	string ToString() const;
};

#endif