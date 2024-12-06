/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdeson <pdeson@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:54:35 by pdeson            #+#    #+#             */
/*   Updated: 2024/10/28 10:52:32 by pdeson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template <typename T = int>
class Array
{
public:
	Array() : _array(NULL), _size(0) {}
	Array(unsigned int n) : _array(new T[n]), _size(n) {}
	Array(Array const &src) : _array(NULL), _size(0) { *this = src; }
	~Array() { delete[] _array; }

	Array &operator=(Array const &rhs)
	{
		if (this != &rhs)
		{
			delete[] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
		}
		return *this;
	}

	T &operator[](unsigned int i)
	{
		if (i >= _size)
			throw std::out_of_range("Array index out of bounds");
		return _array[i];
	}

	unsigned int size() const { return _size; }

private:
	T *_array;
	unsigned int _size;
};

template <typename T>
std::ostream &	operator<<(std::ostream &os, Array<T> &obj) {
    for (unsigned int i = 0; i < obj.size(); ++i) {
        os << "[" << obj[i] << "] ";
    }
    return (os);
}
