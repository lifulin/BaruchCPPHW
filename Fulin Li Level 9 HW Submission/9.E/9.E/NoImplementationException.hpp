// NoImplementationException.hpp
//
// Base class for no implementation exception.
//
// @author Fulin Li
// @version 1.0 12/30/14

#ifndef NoImplementationException_HPP
#define NoImplementationException_HPP

#include "OptionException.hpp"
#include <sstream>
#include <iostream>
using namespace std;

class NoImplementationException : public OptionException
{
private:
	string m_functionName;

public:
	// Constructors and destructor
	NoImplementationException() : OptionException()
	{ // Default constructor
	}

	NoImplementationException(string functionName) : OptionException()
	{ // Constructor accepting erroneous function name

		m_functionName = functionName;
	}

	virtual ~NoImplementationException()
	{ // Destructor
	}

	string GetMessage()
	{
		stringstream stream;

		stream << "No implementation of the " << m_functionName << " function in the derived class";

		return stream.str();
	}
};

#endif