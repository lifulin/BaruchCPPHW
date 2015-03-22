// OptionException.hpp
//
// Base class for Option exception.
//
// @author Fulin Li
// @version 1.0 12/30/14

#ifndef OptionException_HPP
#define OptionException_HPP

#include <iostream>
using namespace std;

class OptionException
{
public:
	// Constructor and destructor
	OptionException()
	{ // Default constructor
	}

	virtual ~OptionException()
	{ // Destructor
	}

	virtual string GetMessage() = 0;
};

#endif