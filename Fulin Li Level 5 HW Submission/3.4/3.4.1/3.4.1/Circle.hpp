// Circle.hpp
//
// Header file for Circles in two dimensions.
//
// @author Fulin Li
// @version 1.0 11/15/14

#ifndef Circle_HPP
#define Circle_HPP

#include "Point.hpp"

class Circle
{
private:
	Point p_center; // Center
	double m_radius; // Radius

public:
	// Constructors
	Circle();
	Circle(const Point& center, double r);
	Circle(const Circle& circle);
	~Circle();
	
	// Accessing functions
	Point CentrePoint() const;
	double Radius() const;
	double Diameter() const;
	double Area() const;
	double Circumference() const;

	// Modifiers
	void CentrePoint(const Point& newCenter);
	void Radius(double newR);
		
	string ToString() const;

	// Member operator overloading
	Circle& operator = (const Circle& source); // Assignment operator

	// Global operator overloading
	friend ostream& operator << (ostream& os, const Circle& c); // Send to ostream
};

#endif
