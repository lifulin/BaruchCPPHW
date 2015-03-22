// Array.hpp
//
// Header file for Array class.
//
// Last Modifications:
// 2014-11-15 Throw an OutOfBoundsException object as exception
//
// @author Fulin Li
// @version 1.1 11/15/14

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
using namespace std;

class Array
{
private:
	Point* m_data; // Dynamic C array of Point objects
	int m_size; // Size of the array

public:
	// Constructors
	Array();
	Array(int size);
	Array(const Array& pp);
	virtual ~Array();

	// Member operator overloading
	Array& operator = (const Array& source);
	Point& operator [] (int index);
	const Point& operator [] (int index) const;

	// Accessing functions
	Point& GetElement(int index) const;
	
	// Modifiers
	void SetElement(int index, const Point& newPoint);
};

#endif