// Point.hpp
//
// Header file for Points in two dimensions.
// 
// Last Modifications:
// 2014-11-8 Add distance functions
//
// @author Fulin Li
// @version 1.1 11/8/14

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

	double DistanceOrigin(); // Calculate the distance to the origin (0, 0).
	double Distance(Point p); // Calculate the distance between two points.
};

#endif
