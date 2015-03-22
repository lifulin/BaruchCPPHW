// TestOperators.cpp
//
// Test program for operators in Point, Line and Circle class.
// 
// Last Modifications:
// 2014-11-9 Test << operator
// 2014-11-9 Trst << operator after declaring the overloading vunction as a friend.
//
// @author Fulin Li
// @version 2.2 11/9/14

#include "Point.hpp"
#include "Line.hpp"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	// Test Point class.
	Point p1(1, -2);
	Point p2(3, 4);
	cout << p1.ToString() << ", " << p2.ToString() << endl;
	
	Point p3 = - p1;
	cout << "- " << p1.ToString() << ", result: " << p3.ToString() << endl;

	p3 = p1 + p2;
	cout << p1.ToString() << " + " << p2.ToString() << ", result: " << p3.ToString() << endl;

	p3 = p1 * 2.0;
	cout << p1.ToString() << " * 2.0, result: " << p3.ToString() << endl;

	cout << "(" << p1.ToString() << " == " << p2.ToString() << "), result: " << (p1 == p2) << endl;

	p3 = p1;
	cout << "p3 = " << p1.ToString() << ", p3 becomes " << p3.ToString() << endl;

	p3 *= 2.0;
	cout << "p3 *= 2.0, p3 becomes " << p3.ToString() << endl;

	// Test << operator in Point class.
	cout << "p1:" << endl;
	cout << p1;

	// Test Line class.
	const Point p4(0, 0);
	const Point p5(4, 5);
	Line l1(p4, p5);
	cout << endl << "l1: " << endl << l1.ToString() << endl;

	Line l2 = l1;
	cout << "l2 = l1" << endl << "l2:" << endl << l2.ToString() << endl;

	// Test << operator in Line class.
	cout << "l1:" << endl;
	cout << l1;
}