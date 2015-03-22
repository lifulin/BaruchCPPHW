// Array.cpp
//
// Header file for Array class.
//
// @author Fulin Li
// @version 1.0 12/05/14

#ifndef Array_CPP
#define Array_CPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp"

// Constructors
template <typename T>
Array<T>::Array() : m_data(new T[10]), m_size(10)
{ // Default constructor.
}

template <typename T>
Array<T>::Array(int size) : m_data(new T[size]), m_size(size)
{
}

template <typename T>
Array<T>::Array(const Array<T>& pt)
{ // Copy constructor
	m_data = new T[pt.m_size];
	m_size = pt.m_size;

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = pt.m_data[i];
	}
}

template <typename T>
Array<T>::~Array()
{ // Destructor
	delete[] m_data;
}

template <typename T>
Array<T>& Array<T>::operator = (const Array<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	delete[] m_data;

	m_data = new T[source.m_size];
	m_size = source.m_size;

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i];
	}

	return *this;
}

template <typename T>
T& Array<T>::operator [] (int index)
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

template <typename T>
const T& Array<T>::operator [] (int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

template <typename T>
T& Array<T>::GetElement(int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

template <typename T>
void Array<T>::SetElement(int index, const T& newT)
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	m_data[index] = newT;
}

#endif
