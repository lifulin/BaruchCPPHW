// FunctionObject.hpp
//
// Header file for FunctionObject class.
//
// @author Fulin Li
// @version 1.0 12/13/14

#ifndef FunctionObject_HPP
#define FunctionObject_HPP

template <typename T>
class FunctionObject
{
private:
	T limit;

public:
	// Constructors
	FunctionObject();
	FunctionObject(const T& t);
	FunctionObject(const FunctionObject<T>& source);

	// Destructor
	~FunctionObject();

	// Member operator overloading
	FunctionObject<T>& operator = (const FunctionObject<T>& source);
	int operator () (const T& t) const;
};

#endif