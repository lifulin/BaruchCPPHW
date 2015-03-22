// IncompatibleSizeException.hpp
//
// Base class for incompatible size exception.
//
// @author Fulin Li
// @version 1.0 12/06/14

#ifndef IncompatibleSizeException_HPP
#define IncompatibleSizeException_HPP

#include "ArrayException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

class IncompatibleSizeException : public ArrayException
{
public:
	// Constructors and destructor
	IncompatibleSizeException() : ArrayException()
	{ // Default constructor
	}

	~IncompatibleSizeException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "Incompatible size of arrays.";

		return stream.str();
	}
};

#endif