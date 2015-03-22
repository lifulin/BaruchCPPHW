// Line.hpp
//
// Header file for Lines in two dimensions.
// 
// @author Fulin Li
// @version 1.0 11/8/14

#ifndef Line_HPP
#define Line_HPP

#include "Point.hpp"
#include <iostream>
using namespace std;

class Line
{
private:
	Point p1; // Start point
	Point p2; // End point

public:
	Line(); // Default constructor
	Line(const Point& p1, const Point& p2); // Constructor with a start- and end-point
	Line(const Line& line); // Copy constructor

	~Line(); // Destructor

	// Accessing functions
	Point P1() const; // Overloaded getter for the start point
	Point P2() const; // Overloaded getter for the end point

	// Modifiers
	void P1(const Point& newP1); // Overloaded setter for the start point
	void P2(const Point& newP2); // Overloaded setter for the end point

	double Length() const; // Return the length of the line.
	string ToString() const; // Return the desciption of the line.
};

#endif