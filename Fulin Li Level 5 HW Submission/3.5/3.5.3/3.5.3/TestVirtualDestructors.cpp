// TestVirtualDestructors.cpp
//
// Test program for virtual destructors.
// 
// @author Fulin Li
// @version 1.0 11/15/14

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Shape* shapes[3];
	shapes[0] = new Shape;
	shapes[1] = new Point;
	shapes[2] = new Line;
	for (int i = 0; i != 3; i++) delete shapes[i];

	// If not declaring Shape destructor as virtual,
	// Point destructor will be called twice,
	// Shape destructor will be called five times.
	// This indicates that the derived class destructor will not be called
	// when the destructor is not declared virtual in the base class,
	// the proper destructors for Point and Line classes are not called.

	// When declaring Shape destructor as virtual, 
	// Point destructor will be called five times,
	// Line destructor will be called once,
	// Shape destructor will be called seven times.
	// The proper destructors are called now.
}