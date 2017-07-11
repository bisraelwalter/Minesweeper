//****Brandon Walter*****
#pragma once
#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Array.h"
#include "Row.h"

#endif


template<class T>
class Row;

template <class T>
class Array2D
{
private:
	Array<T> m_array;
	int m_row;
	int m_col;

public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D& copy);
	~Array2D();
	Array2D &operator=(const Array2D &rhs);
	Array2D &operator=(const Array2D &rhs) const;
	Row<T> operator[](int index);
	Row<T> operator[](int index) const;
	int getRow() const;
	void setRow(int rows);
	int getColumn() const;
	void setColumn(int columns);
	T &Select(int row, int column);
	void loadintData(int data);

};


template<class T>
inline Array2D<T>::Array2D()
{
	this->m_col = 0;
	this->m_row = 0;
	m_array.setLength(this->m_col * this->m_row);
}

template<class T>
inline Array2D<T>::Array2D(int row, int col)
{
	m_array.setLength(row * col);
	this->m_row = row;
	this->m_col = col;
}

template<class T>
inline Array2D<T>::Array2D(const Array2D & copy)
{
	this->m_array = copy.m_array;
	this->m_row = copy.m_row;
	this->m_col = copy.m_col;
}

template<class T>
inline Array2D<T>::~Array2D()
{
}

template<class T>
inline Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	if (this == &rhs)
		return *this;

	this->m_row = rhs.m_row;
	this->m_col = rhs.m_col;


	this->m_array.setLength(this->m_row * this->m_col);
	this->m_array = rhs.m_array;

	return *this;
}

template<class T>
inline Array2D<T> & Array2D<T>::operator=(const Array2D & rhs) const
{
	if (this == &rhs)
		return *this;

	this->m_row = rhs.m_row;
	this->m_col = rhs.m_col;

	if (rhs.m_array.getLength() != 0)
	{
		this->m_array.setLength(m_row * m_col);
		this->m_array = rhs.m_array;
	}

	return *this;
}

template<class T>
inline Row<T> Array2D<T>::operator[](int index)
{
	if (index < 0)
		throw out_of_range("cannot be less than zero");
	if (index > this->m_row - 1)
		throw out_of_range("cannot be greater than the size of the array");

	return Row<T>(*this, index);
}

template<class T>
inline Row<T> Array2D<T>::operator[](int index) const
{
	if (index < 0)
		throw out_of_range("cannot be less than zero");
	if (index > this->m_row - 1)
		throw out_of_range("cannot be greater than the size of the array");

	return Row<T>(*this, index);
}

template<class T>
inline int Array2D<T>::getRow() const
{
	return this->m_row;
}

template<class T>
inline void Array2D<T>::setRow(int rows)
{
	this->m_row = rows;
	this->m_array.setLength(rows * this->m_col);
}

template<class T>
inline int Array2D<T>::getColumn() const
{
	return this->m_col;
}

template<class T>
inline void Array2D<T>::setColumn(int columns)
{
	this->m_col = columns;
	this->m_array.setLength(this->m_row * columns);
}

template<class T>
inline T & Array2D<T>::Select(int row, int column)
{
	if (row == 0)
		return m_array[row + column];
	else
		return m_array[(row * m_col) + column];
}

template<class T>
inline void Array2D<T>::loadintData(int data)
{
	for (int i = 0; i < this->m_row * this->m_col; i++)
		this->m_array[i] = i + data;
}
