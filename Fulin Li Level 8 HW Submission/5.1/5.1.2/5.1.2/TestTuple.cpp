// TestTuple.cpp
//
// Test program for tuple.
//
// @author Fulin Li
// @version 1.0 12/14/14

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <string>
#include <iostream>
using namespace std;

void Print(const boost::tuple<string, int, int>& person)
{
	cout << "Name: " << person.get<0>() << "; Age: "
		<< person.get<1>() << "; Length: " << person.get<2>() << endl;
}

void main()
{
	using boost::tuple;
	typedef boost::tuple<string, int, int> Person;

	// Create person instances.
	Person p1 = boost::make_tuple(string("John"), 20, 160);
	Person p2 = boost::make_tuple(string("Mary"), 21, 170);
	Person p3 = boost::make_tuple(string("Alice"), 22, 180);

	// Increment the age of one person.
	p2.get<1>() += 3;
	Print(p1);
	Print(p2);
	Print(p3);
}