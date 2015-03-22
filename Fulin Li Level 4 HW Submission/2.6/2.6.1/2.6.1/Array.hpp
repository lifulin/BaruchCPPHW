// Array.hpp
//
// Header file for Array class.
//
// Last Modifications:
// 2014-11-9 Place class in namespace
//
// @author Fulin Li
// @version 1.1 11/9/14

#ifndef Array_HPP
#define Array_HPP

#include "Point.hpp"
using namespace std;

namespace FULINLI
{
	namespace Containers
	{
		class Array
		{
		private:
			CAD::Point* m_data; // Dynamic C array of Point objects
			int m_size; // Size of the array

		public:
			// Constructors
			Array();
			Array(int size);
			Array(const Array& pp);
			~Array();

			// Member operator overloading
			Array& operator = (const Array& source);
			CAD::Point& operator [] (int index);
			const CAD::Point& operator [] (int index) const;

			// Accessing functions
			int Size() const;
			CAD::Point& GetElement(int index) const;

			// Modifiers
			void SetElement(int index, const CAD::Point& newPoint);
		};
	}
}

#endif