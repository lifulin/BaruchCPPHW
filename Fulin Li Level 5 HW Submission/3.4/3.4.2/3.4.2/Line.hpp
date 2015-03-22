// Line.hpp
//
// Header file for Lines in two dimensions.
//
// @author Fulin Li
// @version 1.1 11/15/14

#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include "Shape.hpp"
#include <iostream>
using namespace std;

class Line : public Shape
{
private:
	Point p1; // Start point
	Point p2; // End point

public:
	// Constructors and destructor
	Line(); // Default constructor
	Line(const Line& line); // Copy constructor
	Line(const Point& val1, const Point& val2); // Constructor accepting two points
	virtual ~Line(); // Destructor

	// Member operator overloading
	Line& operator = (const Line& source); // Assignment operator

	// Global operator overloading
	friend ostream& operator << (ostream& os, const Line& l); // Send to ostream

	string ToString() const;
};

#endif