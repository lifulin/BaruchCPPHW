// TestPoint.cpp
//
// Test program for Point class.
//
// @author Fulin Li
// @version 1.0 11/9/14

#include "Point.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Point p(1.0, 1.0);
	//if (p == 1.0) cout << "Equal!" << endl;
	//else cout << "Not equal" << endl;
	
	if (p == (Point)1.0) cout << "Equal!" << endl;
}