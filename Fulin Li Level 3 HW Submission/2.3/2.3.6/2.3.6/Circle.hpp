// Circle.hpp
//
// Header file for Circles in two dimensions.
// 
// @author Fulin Li
// @version 1.0 11/8/14

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"

class Circle
{
private:
	Point p_center;
	double m_radius;

public:
	Circle(); // Default constructor
	Circle(const Point& center, double r); // Constructor with a center point and radius
	Circle(const Circle& circle); // Copy constructor

	~Circle(); // Destructor
	
	// Getter functions for center and radius
	Point CentrePoint() const;
	double Radius() const;

	// Setter functions for center and radius
	void CentrePoint(const Point& newCenter);
	void Radius(double newR);
	
	// Getter functions for other parameters
	double Diameter() const;
	double Area() const;
	double Circumference() const;

	string ToString() const; // Return description of the circle.
};

#endif
