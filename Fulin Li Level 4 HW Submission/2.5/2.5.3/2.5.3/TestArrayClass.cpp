// TestArrayClass.cpp
//
// Test program for array class.
// 
// @author Fulin Li
// @version 1.0 11/9/14

#include "Point.hpp"
#include "Array.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	// Use default constructor.
	Array array1;

	// Use constructor with size as argument.
	Array array2(2);

	// Test [] operator for writing.
	array2[0] = Point(0.5, 1.5);
	array2[1] = Point(1.0, 2.5);

	// Test assignment operator.
	array1 = array2;
	for (int i = 0; i < array1.Size(); i++)
	{
		cout << array1[i] << endl;
	}

	// Test Size(), [] operator for reading.
	cout << "Size: " << array2.Size() << endl << "Elements: " << array2[0] << ", " << array2[1] << endl;

	// Test GetElement().
	cout << "Size: " << array2.Size() << endl << "Elements: " << array2.GetElement(0) << ", " << array2.GetElement(1) << endl;

	// Test SetElement().
	array2.SetElement(0, Point(2.3, 7.7));
	array2.SetElement(1, Point(4.5, 3.2));
	cout << "Size: " << array2.Size() << endl << "Elements: " << array2[0] << ", " << array2[1] << endl;

	// Using copy constructor.
	Array array3(array2);
	cout << "Size: " << array3.Size() << endl << "Elements: " << array3[0] << ", " << array3[1] << endl;

	// Test [] operator for const Array object.
	const Array array4(array2);
	cout << "Size: " << array4.Size() << endl << "Elements: " << array4[0] << ", " << array4[1] << endl;
}