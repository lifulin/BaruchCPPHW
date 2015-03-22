// TestStack.cpp
//
// Test program for Stack class.
//
// Last Modifications:
//
// 2014-12-06 Throw stack exception
// 2014-12-06 Test value template parameter
//
// @author Fulin Li
// @version 1.1 12/06/14

#include "Stack.cpp"
#include <iostream>
using namespace std;

void main()
{
	// Test defalut constructor.
	Stack<int, 10> s0;
	
	// Test Push().
	for (int i = 0; i < 11; i++)
	{
		try
		{
			s0.Push(i);
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}

	// Test copy constructor.
	Stack<int, 10> s1(s0);
	
	// Test assignment operator.
	Stack<int, 10> s2 = s0;

	// Test Pop().
	for (int i = 0; i < 11; i++)
	{
		try
		{
			cout << s0.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}

		try
		{
			cout << s1.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}

		try
		{
			cout << s2.Pop() << endl;
		}
		catch (StackException& ex)
		{
			cout << ex.GetMessage() << endl;
		}
	}
}