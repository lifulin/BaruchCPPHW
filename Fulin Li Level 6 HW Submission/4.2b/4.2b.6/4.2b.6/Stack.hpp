// Stack.hpp
//
// Header file for Stack class.
//
// Last Modifications:
// 2014-12-06 Add value template argument
//
// @author Fulin Li
// @version 1.1 12/06/14

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.cpp"

template <typename T, int size>
class Stack
{
private:
	int m_current;
	Array<T> m_array;

public:
	// Constructors
	Stack();
	Stack(const Stack<T, size>& ps);

	// Destructor
	~Stack();

	// Member operator overloading
	Stack<T, size>& operator = (const Stack<T, size>& source);
	
	// Functionalities
	T& Pop();
	void Push(const T& newT);
};

#endif