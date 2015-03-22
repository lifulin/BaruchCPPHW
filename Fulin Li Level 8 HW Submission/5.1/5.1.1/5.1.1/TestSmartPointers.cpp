// TestSmartPointers.cpp
//
// Test program for smart pointers.
//
// @author Fulin Li
// @version 1.0 12/14/14

#include <boost\shared_ptr.hpp>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Array.cpp"
#include <iostream>

void main()
{
	typedef boost::shared_ptr<Shape> ShapePtr;
	typedef Array<ShapePtr> ShapeArray;

	const int size = 3;
	
	ShapePtr p_shape1(new Point(0.1, 0.2));
	ShapePtr p_shape2(new Line(Point(0.0, 0.0), Point(1.0, 1.0)));
	ShapePtr p_shape3(new Circle(Point(0.0, 0.0), 1.0));
	
	{
		// Create an array with shared pointers for shapes.
		ShapeArray array_shape(size);

		// Fill the array with various shapes.
		array_shape[0] = p_shape1;
		array_shape[1] = p_shape2;
		array_shape[2] = p_shape3;

		// Print the shapes.
		for (int i = 0; i < size; i++)
		{
			cout << array_shape[i]->ToString() << endl;
		}

		cout << p_shape1.use_count() << endl;
		cout << p_shape2.use_count() << endl;
		cout << p_shape3.use_count() << endl;
	}

	// The shapes are automatically deleted.
	cout << p_shape1.use_count() << endl;
	cout << p_shape2.use_count() << endl;
	cout << p_shape3.use_count() << endl;
}