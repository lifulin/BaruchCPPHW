// Line.cpp
//
// Header file for Lines in two dimensions.
// 
// Last Modifications:
// 2014-11-9 Add assignment operator
// 2014-11-9 Add << operator
// 2014-11-9 Move the << operator inside the class definition and declare it as friend
// 2014-11-9 Place class in namespace
//
// @author Fulin Li
// @version 2.3 11/9/14

#include "Line.hpp"
#include "Point.hpp"
#include <sstream>

namespace FULINLI
{
	namespace CAD
	{
		Line::Line() : p1(0, 0), p2(0, 0)
		{
		}

		Line::Line(const Point& p1, const Point& p2) : p1(p1), p2(p2)
		{
		}

		Line::Line(const Line& line) : p1(line.p1), p2(line.p2)
		{
		}

		Line::~Line()
		{
		}

		Point Line::P1() const
		{
			return p1;
		}

		Point Line::P2() const
		{
			return p2;
		}

		void Line::P1(const Point& newP1)
		{
			p1 = newP1;
		}

		void Line::P2(const Point& newP2)
		{
			p2 = newP2;
		}

		double Line::Length() const
		{
			return p1.Distance(p2);
		}

		string Line::ToString() const
		{
			stringstream stream;

			stream << "Line: " << p1.ToString() << "-" << p2.ToString();

			return stream.str();
		}

		Line& Line::operator = (const Line& source)
		{ // Assignment operator.

			if (this == &source)
			{
				return *this;
			}

			p1 = source.p1;
			p2 = source.p2;

			return *this;
		}

		ostream& operator << (ostream& os, const Line& l)
		{ // Send to ostream

			os << "Line: " << l.p1 << "-" << l.p2 << endl;

			return os;
		}
	}
}