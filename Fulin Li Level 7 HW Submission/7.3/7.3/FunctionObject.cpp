// FunctionObject.cpp
//
// Header file for FunctionObject class.
//
// @author Fulin Li
// @version 1.0 12/13/14

#ifndef FunctionObject_CPP
#define FunctionObject_CPP

#include "FunctionObject.hpp"

// Constructors
template <typename T>
FunctionObject<T>::FunctionObject()
{ // Default constructor.
}

template <typename T>
FunctionObject<T>::FunctionObject(const T& t) : limit(t)
{ // Constructor with the limit value as input.
}

template <typename T>
FunctionObject<T>::FunctionObject(const FunctionObject<T>& source) : limit(source.limit)
{ // Copy constructor.
}

template <typename T>
FunctionObject<T>::~FunctionObject()
{ // Destructor.
}

template <typename T>
FunctionObject<T>& FunctionObject<T>::operator = (const FunctionObject<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	limit = source.limit;
	return *this;
}

template <typename T>
int FunctionObject<T>::operator () (const T& t) const
{ // () operator
	return t < limit;
}

#endif