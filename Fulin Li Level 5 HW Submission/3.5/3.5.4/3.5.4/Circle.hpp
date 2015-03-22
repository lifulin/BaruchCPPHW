// Circle.hpp
//
// Header file for Circles in two dimensions.
//
// Last Modifications:
// 2014-11-15 Call the ToString() method of the Shape base class in the ToString() method of the derived class
// 2014-11-15 Add Draw() function
//
// @author Fulin Li
// @version 1.3 11/15/14

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

	// Functionalities
	void Draw() const;
};

#endif