// ArrayException.hpp
//
// Base class for Array exception.
//
// Last Modifications:
// 2014-11-15 Throw an OutOfBoundsException object as exception
//
// @author Fulin Li
// @version 1.1 11/15/14

#ifndef ArrayException_HPP
#define ArrayException_HPP

#include <iostream>
using namespace std;

class ArrayException
{
public:
	// Constructor and destructor
	ArrayException()
	{ // Default constructor
	}

	virtual ~ArrayException()
	{ // Destructor
	}

	virtual string GetMessage() = 0;
};

#endif