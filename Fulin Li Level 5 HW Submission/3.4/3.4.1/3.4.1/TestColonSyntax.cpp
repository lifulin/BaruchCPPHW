// TestColonSyntax.cpp
//
// Test program for colon syntax.
// 
// @author Fulin Li
// @version 1.0 11/15/14

#include "Line.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	Line l;

	// Without using colon sytax:
	// The default constructor is called twice.
	// The constructor accepts x- and y-coordinates is called twice.
	// The assignment operator is called twice.
	// The destructor is called four times.

	// Using colon sytax:
	// The constructor accepts x- and y-coordinates is called twice.
	// The destructor is called twice.

	// Thus, using the colon syntax, the number of point constructor, destructor and assignment calls is less than before.
}