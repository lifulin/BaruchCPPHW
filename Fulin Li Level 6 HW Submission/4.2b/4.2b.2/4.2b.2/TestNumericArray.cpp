// TestNumericArray.cpp
//
// Test program for NumericArray class.
//
// @author Fulin Li
// @version 1.0 12/06/14

#include "NumericArray.cpp"
#include "Array.cpp"
#include "ArrayException.hpp"
#include <iostream>
using namespace std;

void main()
{
	// Test default constructor.
	NumericArray<int> array0;
	cout << "NumericArray0: " << endl << "size = " << array0.Size() << endl;

	// Test constructor with size as input.
	NumericArray<int> array1(2);
	array1[0] = 1;
	array1[1] = 2;
	cout << "NumericArray1: " << endl << array1[0] << "," << array1[1] << endl;

	// Test copy constructor.
	NumericArray<int> array2(array1);
	cout << "NumericArray2: " << endl << array2[0] << "," << array2[1] << endl;

	// Test constructor with size as input.
	NumericArray<int> array3(3);
	cout << "NumericArray3: " << endl;
	for (int i = 0; i < array3.Size(); i++)
	{
		array3[i] = 3;
		cout << array3[i] << endl;
	}

	// Test assignment operator.
	NumericArray<int> array4 = array1;
	cout << "NumericArray4: " << endl;
	for (int i = 0; i < array4.Size(); i++)
	{
		cout << array4[i] << endl;
	}

	// Test * operator.
	NumericArray<int> array5 = array2 * 3;
	cout << "NumericArray5: " << endl;
	for (int i = 0; i < array5.Size(); i++)
	{
		cout << array5[i] << endl;
	}

	// Test + operator and case with incompatible size.
	NumericArray<int> array6(2);
	array6 = array1 + array2;
	cout << "NumericArray6: " << endl;
	for (int i = 0; i < array6.Size(); i++)
	{
		cout << array6[i] << endl;
	}

	NumericArray<int> array7;
	cout << "NumericArray7: " << endl;

	try
	{
		array7 = array1 + array3;
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	// Test dot product and case with incompatible size.
	int dot_product8;
	cout << "dot_product8: " << endl;
	dot_product8 = array1.DotProduct(array2);
	cout << dot_product8 << endl;
	
	int dot_product9;
	cout << "dot_product9: " << endl;

	try
	{
		dot_product9 = array1.DotProduct(array3);
	}
	catch (ArrayException& ex)
	{
		cout << ex.GetMessage() << endl;
	}

	// The type used as template argument should support numeric operations
	// including +, * and dot product.
	// Although we can create a numeric array with Point objects, 
	// we cannot perform the above operations because the Point class does not have them.
}