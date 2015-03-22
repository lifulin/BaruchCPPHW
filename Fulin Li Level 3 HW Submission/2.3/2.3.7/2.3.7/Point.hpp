// Point.hpp
//
// Header file for Points in two dimensions.
// 
// Last Modifications:
// 2014-11-8 Add distance functions
// 2014-11-8 Add copy constructor and a constructor that accepts x- and y-coordinates
// 2014-11-8 Pass by reference in the Distance() function
// 2014-11-8 Rename DistanceOrigin() to Distance(), rename getter and setter functions
// 2014-11-8 Mark X(), Y(), Distance() and ToString() as const
// 2014-11-8 Delete the setter and getter functions
// 2014-11-8 Restore the setter and getter functions, and make them inline functions
//
// @author Fulin Li
// @version 1.7 11/8/14

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
	Point(const Point& point); // Copy constructor
	Point(double xValue, double yValue); // Constructor that accepts x- and y-coordinates

	~Point(); // Destructor

	// Accessing functions
	double X() const; // Getter function for x-coordinate
	double Y() const; // Getter function for y-coordinate

	// Modifiers
	void X(double newX) { m_x = newX; } // Setter function for x-coordinate
	void Y(double newY) { m_y = newY; } // Setter function for y-coordinate

	string ToString() const; // String description of the point

	double Distance() const; // Calculate the distance to the origin (0, 0).
	double Distance(const Point& p) const; // Calculate the distance between two points.
};

inline double Point::X() const { return m_x; }
inline double Point::Y() const { return m_y; }

#endif
