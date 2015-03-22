// Shape.hpp
//
// Base class for Shapes.
//
// @author Fulin Li
// @version 1.0 11/15/14

#ifndef Shape_HPP
#define Shape_HPP

#include <iostream>
using namespace std;

class Shape
{
private:
	int m_id; // ID

public:
	// Constructors and destructor
	Shape(); // Constructor
	Shape(const Shape& source); // Copy constructor
	virtual ~Shape(); // Destructor

	// Operator overloading
	Shape& operator = (const Shape& source); // Assignment operator

	string ToString() const;

	// Accessing functions
	int ID() const;
};

#endif


