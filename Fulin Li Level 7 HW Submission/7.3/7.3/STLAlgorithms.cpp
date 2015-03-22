// STLAlgorithms.cpp
//
// Test program for STL Algorithms.
//
// @author Fulin Li
// @version 1.0 12/13/14

#include <vector>
#include <algorithm>
#include <iostream>
#include "FunctionObject.cpp"
using namespace std;

// Global function checking the input is less than a certain value.
int LessThanLimit(double input)
{
	const double limit = 10.0;
	return input < limit;
}

void main()
{
	// Create a vector with 20 elements.
	vector<double> vector1;
	for (int i = 0; i < 20; i++)
	{
		vector1.push_back(i + 0.1);
	}

	// Using the global function to get the number of elements less than a certain value.
	int result1 = count_if(vector1.begin(), vector1.end(), LessThanLimit);
	cout << "The number of elements that are less than 10 is " << result1 << endl;

	// Using the function object to get the number of elements less than a certain value.
	double limit = 10.0;
	int result2 = count_if(vector1.begin(), vector1.end(), FunctionObject<double>(limit));
	cout << "The number of elements that are less than " << limit << " is " << result2 << endl;
}
