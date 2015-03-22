// Stack.hpp
//
// Header file for Stack class.
//
// @author Fulin Li
// @version 1.0 12/06/14

#ifndef Stack_HPP
#define Stack_HPP

#include "Array.cpp"

template <typename T>
class Stack
{
private:
	int m_current;
	Array<T> m_array;

public:
	// Constructors
	Stack();
	Stack(int size);
	Stack(const Stack<T>& ps);

	// Destructor
	~Stack();

	// Member operator overloading
	Stack<T>& operator = (const Stack<T>& source);
	
	// Functionalities
	T& Pop();
	void Push(const T& newT);
};

#endif