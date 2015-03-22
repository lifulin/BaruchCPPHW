// Shape.hpp
//
// Base class for Shapes.
//
// Last Modifications:
// 2014-11-15 Declare the ToString() function as virtual
//
// @author Fulin Li
// @version 1.1 11/15/14

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

	virtual string ToString() const;

	// Accessing functions
	int ID() const;
};

#endif


