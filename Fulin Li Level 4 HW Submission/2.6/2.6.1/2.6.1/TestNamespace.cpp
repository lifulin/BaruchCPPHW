// TestNamespace.cpp
//
// Test program for namespace.
// 
// @author Fulin Li
// @version 1.0 11/9/14

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>

void main()
{
	// The full namespace for Point class.
	FULINLI::CAD::Point p1(0.1, 0.2);
	FULINLI::CAD::Point p2(2.1, 7.6);
	cout << p1 << ", " << p2 << endl;

	// Using declaration for using a single class (Line).
	using FULINLI::CAD::Line;
	cout << Line(p1, p2);
	
	// Using declaration for a complete namespace (Containers).
	using namespace FULINLI::Containers;
	Array array1(3);
	array1[0] = FULINLI::CAD::Point(2.3, 5.5);
	cout << array1[0] << endl;

	// Using the Circle class by creating a shorter alias.
	namespace FCAD = FULINLI::CAD;
	using FCAD::Circle;
	Circle sc(FCAD::Point(0, 0), 1);
	cout << sc;
}
