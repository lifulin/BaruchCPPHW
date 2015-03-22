// OutOfBoundsException.hpp
//
// Base class for out of bound exception.
//
// @author Fulin Li
// @version 1.0 11/15/14

#ifndef OutOfBoundsException_HPP
#define OutOfBoundsException_HPP

#include "ArrayException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

class OutOfBoundsException : public ArrayException
{
private:
	int m_index;

public:
	// Constructors and destructor
	OutOfBoundsException() : ArrayException()
	{ // Default constructor
	}

	OutOfBoundsException(int index) : ArrayException()
	{ // Constructor accepting erroneous array index
		m_index = index;
	}

	virtual ~OutOfBoundsException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;
		
		stream << "Index " << m_index << " is out of bound.";

		return stream.str();
	}
};

#endif