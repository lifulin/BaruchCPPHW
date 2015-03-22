// NumericArray.cpp
//
// Header file for NumericArray class.
//
// @author Fulin Li
// @version 1.0 12/06/14

#ifndef NumericArray_CPP
#define NumericArray_CPP

#include "NumericArray.hpp"
#include "IncompatibleSizeException.hpp"

// Constructors
template <typename T>
NumericArray<T>::NumericArray() : Array()
{ // Default constructor.
}

template <typename T>
NumericArray<T>::NumericArray(int size) : Array(size)
{
}

template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& pn) : Array(pn)
{ // Copy constructor.
}

template <typename T>
NumericArray<T>::~NumericArray()
{ // Destructor
}

// Member operator overloading
template <typename T>
NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source)
	{
		return *this;
	}

	// Call base class assignment
	Array<T>::operator = (source);
	
	return *this;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator * (const T& factor) const
{
	NumericArray<T> result(*this);
	
	for (int i = 0; i < result.Size(); i++)
	{
		result[i] *= factor;
	}

	return result;
}

template <typename T>
NumericArray<T> NumericArray<T>::operator + (const NumericArray<T>& n2) const
{
	if (Array<T>::Size() != n2.Size())
	{
		throw IncompatibleSizeException();
	}

	NumericArray<T> result(*this);

	for (int i = 0; i < result.Size(); i++)
	{
		result[i] += n2[i];
	}

	return result;
}

// Numeric functionality
template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& n2) const
{ // Dot product.

	if (Array<T>::Size() != n2.Size())
	{
		throw IncompatibleSizeException();
	}

	T result(0);
	
	for (int i = 0; i < Array<T>::Size(); i++)
	{
		result += (Array<T>::operator [] (i) * n2[i]);
	}

	return result;
}

#endif
