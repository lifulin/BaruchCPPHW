// TestTemplateMethodPattern.cpp
//
// Test program for template method pattern.
// 
// @author Fulin Li
// @version 1.0 11/15/14

#include "Shape.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Point p(0.1, 0.2);
	Line l(Point(0.0, 0.5), Point(2.1, 3.3));
	p.Print();
	l.Print();

	// It prints the right information even when point and line do not have the Print() function.
}