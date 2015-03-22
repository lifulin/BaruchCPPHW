// Array.cpp
//
// Header file for Array class.
//
// Last Modifications:
// 2014-11-15 Throw an OutOfBoundsException object as exception
//
// @author Fulin Li
// @version 1.1 11/15/14

#include "Point.hpp"
#include "Array.hpp"
#include "OutOfBoundsException.hpp"
using namespace std;

Array::Array() : m_data(new Point[10]), m_size(10)
{
}

Array::Array(int size) : m_data(new Point[size]), m_size(size)
{
}

Array::Array(const Array& pp)
{
	m_data = new Point[pp.m_size];
	m_size = pp.m_size;

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = pp.m_data[i];
	}
}

Array::~Array()
{
	delete[] m_data;
}

Array& Array::operator = (const Array& source)
{
	if (this == &source)
	{
		return *this;
	}

	delete[] m_data;

	m_data = new Point[source.m_size];
	m_size = source.m_size;

	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source.m_data[i];
	}

	return *this;
}

Point& Array::operator [] (int index)
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

const Point& Array::operator [] (int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

Point& Array::GetElement(int index) const
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	return m_data[index];
}

void Array::SetElement(int index, const Point& newPoint)
{
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	m_data[index] = newPoint;
}
