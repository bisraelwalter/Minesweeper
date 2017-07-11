//****Brandon Walter*****
#pragma once
#ifndef ROW_H
#define ROW_H

template <class T>
class Array2D;

template <class T>
class Row
{
private:
	Array2D<T> &m_array2d;
	int m_row;

public:
	Row(Array2D<T> &array, int row);
	T &operator[](int column);
};


#endif

template<class T>
inline Row<T>::Row(Array2D<T>& array, int row) : m_array2d(array), m_row(row) {}

template<class T>
inline T & Row<T>::operator[](int column)
{
	if (column < 0)
		throw out_of_range("Column cannot be less than zero");
	if (column > m_array2d.getColumn() - 1)
		throw out_of_range("Cannot be greater than size of array");

	return this->m_array2d.Select(m_row, column);
}

