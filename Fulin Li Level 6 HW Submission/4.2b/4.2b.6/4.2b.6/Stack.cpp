// Stack.cpp
//
// Header file for Stack class.
//
// Last Modifications:
// 2014-12-06 Add value template argument
//
// @author Fulin Li
// @version 1.1 12/06/14

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
#include "StackException.hpp"

// Constructors
template <typename T, int size>
Stack<T, size>::Stack() : m_current(0), m_array(size)
{ // Default constructor.
}

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& pt) : m_current(pt.m_current), m_array(pt.m_array)
{ // Copy constructor
}

template <typename T, int size>
Stack<T, size>::~Stack()
{ // Destructor
}

template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator = (const Stack<T, size>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_current = source.m_current;
	m_array = source.m_array;

	return *this;
}

template <typename T, int size>
T& Stack<T, size>::Pop()
{
	T t;

	try
	{
		t = m_array[m_current - 1];
	}
	catch (ArrayException& ex)
	{
		throw StackEmptyException();
	}
	
	m_current--;
	return t;
}

template <typename T, int size>
void Stack<T, size>::Push(const T& newT)
{
	try
	{
		m_array[m_current] = newT;
	}
	catch (ArrayException& ex)
	{
		throw StackFullException();
	}
	
	m_current++;
}

#endif
