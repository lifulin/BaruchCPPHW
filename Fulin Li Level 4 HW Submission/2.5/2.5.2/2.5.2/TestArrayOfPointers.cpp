// TestArrayOfPointers.cpp
//
// Test program for array of pointers.
// 
// @author Fulin Li
// @version 1.0 11/9/14

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	const int size = 3;

	// Create an array of Point pointers with 3 elements on the heap.
	Point** array_pp = new Point*[size];

	// Create for each element in the array a point on the heap.
	array_pp[0] = new Point(0.0, 0.0);
	array_pp[1] = new Point(1.5, 2.0);
	array_pp[2] = new Point(3.5, 5.5);

	// Print each point in the array.
	for (int i = 0; i < 3; i++)
	{
		cout << *array_pp[i] << endl;
	}

	// Delete each point in the array.
	for (int i = 0; i < 3; i++)
	{
		delete array_pp[i];
	}

	// Delete the array itself.
	delete[] array_pp;

	// Please check memory layout in "Fulin Li Level 4 HW Submission\2.5\2.5.2\Memory_Layout_FulinLi_20141111.jpg"
}
