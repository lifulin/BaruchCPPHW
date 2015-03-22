// TestVariant.cpp
//
// Test program for variant.
//
// @author Fulin Li
// @version 1.0 12/21/14

#include <boost/variant.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"
#include <string>
#include <iostream>
using namespace std;

typedef boost::variant<Point, Line, Circle> ShapeType;

ShapeType Create()
{
	ShapeType shape;

	// Ask the user for the shape type to create.
	cout << "Please choose the shape:" << endl << "a Point; b Line; c Circle" << endl;
	char choice;
	cin >> choice;

	// Create the requested shape and return.
	switch (choice)
	{
		case 'a':
			shape = Point();
			break;
		case 'b':
			shape = Line();
			break;
		case 'c':
			shape = Circle();
			break;
		default:
			break;
	}

	return shape;
}

void main()
{
	using boost::variant;
	
	ShapeType result = Create();
	cout << result << endl;

	try
	{
		Line l1 = boost::get<Line>(result);
	}
	catch (boost::bad_get& err)
	{
		cout << "Error: " << err.what() << endl;
	}

	// Move the shape.
	Visitor visitor(1.0, 2.0);
	boost::apply_visitor(visitor, result);
	cout << result << endl;
}