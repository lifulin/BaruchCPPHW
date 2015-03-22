// TestOperators.cpp
//
// Test program for operators in Point, Line and Circle class.
//
// @author Fulin Li
// @version 2.0 11/9/14

#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
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

	// Test Line class.
	const Point p4(0, 0);
	const Point p5(4, 5);
	Line l1(p4, p5);
	cout << "l1: " << endl << l1.ToString() << endl;

	Line l2 = l1;
	cout << "l2 = l1" << endl << "l2: " << endl << l2.ToString() << endl;

	// Test Circle class.
	const Point p_center(0, 0);
	double m_radius = 1.0;
	Circle c1(p_center, m_radius);
	cout << "c1: " << endl << c1.ToString() << endl;

	Circle c2 = c1;
	cout << "c2 = c1" << endl << "c2: " << endl << c2.ToString() << endl;
}