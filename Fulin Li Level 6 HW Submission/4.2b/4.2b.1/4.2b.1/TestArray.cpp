// TestArray.cpp
//
// Test program for Array class.
// 
// Last Modifications:
// 2014-12-06 Test static variable for array default size and static member functions
//
// @author Fulin Li
// @version 1.1 12/06/14

#include "Array.cpp"
#include <iostream>
using namespace std;

void main()
{
	Array<int> intArray1;
	Array<int> intArray2;
	Array<double> doubleArray;
	cout << intArray1.DefaultSize() << endl; // 10, the default size is 10.
	cout << intArray2.DefaultSize() << endl; // 10, the default size is 10.
	cout << doubleArray.DefaultSize() << endl; // 10, the default size is 10.
	intArray1.DefaultSize(15);
	// The default size of intArray1 is set to 15.
	cout << intArray1.DefaultSize() << endl; // 15
	// Static data member is independent of any particular object of the class Array<int>,
	// so when the default size of intArray1 is set to 15, the default size of intArray2 is also 15.
	cout << intArray2.DefaultSize() << endl; // 15
	// doubleArray is an instance of class Array<double> rather than Array<int>,
	// so when the default size of intArray1 is set to 15, the default size of doubleArray is still 10.
	cout << doubleArray.DefaultSize() << endl; // 10
}
