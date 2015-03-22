// Stack.cpp
//
// Header file for Stack class.
//
// @author Fulin Li
// @version 1.0 12/06/14

#ifndef Stack_CPP
#define Stack_CPP

#include "Stack.hpp"
#include "StackException.hpp"

// Constructors
template <typename T>
Stack<T>::Stack() : m_current(0)
{ // Default constructor.
}

template <typename T>
Stack<T>::Stack(int size) : m_current(0), m_array(size)
{
}

template <typename T>
Stack<T>::Stack(const Stack<T>& pt) : m_current(pt.m_current), m_array(pt.m_array)
{ // Copy constructor
}

template <typename T>
Stack<T>::~Stack()
{ // Destructor
}

template <typename T>
Stack<T>& Stack<T>::operator = (const Stack<T>& source)
{ // Assignment operator
	if (this == &source)
	{
		return *this;
	}

	m_current = source.m_current;
	m_array = source.m_array;

	return *this;
}

template <typename T>
T& Stack<T>::Pop()
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

template <typename T>
void Stack<T>::Push(const T& newT)
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
