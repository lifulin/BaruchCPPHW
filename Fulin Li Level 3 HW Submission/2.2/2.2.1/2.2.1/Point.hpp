// Point.hpp
//
// Header file for Points in two dimensions.
// 
// @author Fulin Li
// @version 1.0 11/08/14

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

class Point
{
private:
	double m_x; // x-coordinate
	double m_y; // y-coordinate

public:
	Point(); // Default constructor

	~Point(); // Destructor

	// Accessing functions
	double GetX(); // Getter function for x-coordinate
	double GetY(); // Getter function for y-coordinate

	// Modifiers
	void SetX(double newX); // Setter function for x-coordinate
	void SetY(double newY); // Setter function for y-coordinate

	string ToString(); // String description of the point
};

#endif
