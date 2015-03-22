// Point.hpp
//
// Header file for Points in two dimensions.
//
// Last Modifications:
// 2014-11-9 Add operators
// 2014-11-9 Add << operator
// 2014-11-9 Declare a constructor that sets x- and y-coordinates to the same value as explicit
// 2014-11-9 Move the << operator inside the class definition and declare it as friend
// 2014-11-9 Place class in namespace
//
// @author Fulin Li
// @version 2.4 11/9/14

#ifndef Point_HPP
#define Point_HPP

#include <iostream>
using namespace std;

namespace FULINLI
{
	namespace CAD
	{
		class Point
		{
		private:
			double m_x; // x-coordinate
			double m_y; // y-coordinate

		public:
			// Constructors
			Point();
			Point(const Point& point);
			Point(double xValue, double yValue);
			~Point();

			// Accessing functions
			double X() const;
			double Y() const;

			// Modifiers
			void X(double newX);
			void Y(double newY);

			string ToString() const;

			// Functionality
			double Distance() const;
			double Distance(const Point& p) const;

			// Member operator overloading
			Point operator - () const; // Negate the coordinates
			Point operator * (double factor) const; // Scale the coordinates
			Point operator + (const Point& p) const; // Add coordinates
			bool operator == (const Point& p) const; // Equally compare operator
			Point& operator = (const Point& source); // Assignment operator
			Point& operator *= (double factor); // Scale the coordinates & assign

			// Global operator overloading
			friend ostream& operator << (ostream& os, const Point& p); // Send to ostream
		};
	}
}

#endif
