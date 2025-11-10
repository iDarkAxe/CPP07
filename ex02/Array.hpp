#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <cstddef>
#include <iomanip>
#include <iostream>

#ifndef DEBUG
# define DEBUG 1
#endif

template <class T>
class Array
{
private:
	T *_array;
	size_t _size;

public:
	Array(void)
	{
		_array = new T[0];
		_size = 0;
	}

	Array(int n)
	{
		if (n < 0)
		{
			if (DEBUG)
				std::cout << "Cannot create array of negative size " << n << std::endl;
			throw OutOfBoundsException();
		}
		_array = new T[n];
		_size = n;
		for (int i = 0; i < n; ++i)
			_array[i] = T();
	}

	~Array(void)
	{
		delete[] _array;
	}

	Array(const Array &src)
	{
		this->_array = new T[src._size];
		this->_size = src._size;
		for (size_t i = 0; i < this->_size; ++i)
			this->_array[i] = src._array[i];
	}

	Array &operator=(const Array &other)
	{
		if (this == &other)
			return *this;
		delete[] _array;
		this->_size = other._size;
		this->_array = new T[this->_size];
		for (size_t i = 0; i < this->_size; ++i)
			this->_array[i] = other._array[i];
		return *this;
	}

	T &operator[](int index)
	{
		if (index < 0 || static_cast<size_t>(index) >= _size)
		{
			if (DEBUG)
				std::cout << "Array[" << index << "] out of bounds for array of size " << _size << std::endl;
			throw OutOfBoundsException();
		}
		return _array[index];
	}

	size_t size(void) const
	{
		return _size;
	}

	void printAsASCII(size_t nbr_elements) const
	{
		for (size_t i = 0; i < nbr_elements; i++)
		{
			std::cout << "numbers[" << std::setw(3) << std::setfill(' ') << i << "] = " << static_cast<int>(_array[i]) << " -> " << static_cast<char>(_array[i]) << std::endl;
		}
	}

	void print(size_t nbr_elements) const
	{
		for (size_t i = 0; i < nbr_elements; i++)
		{
			std::cout << "numbers[" << std::setw(3) << std::setfill(' ') << i << "] = " << static_cast<int>(_array[i]) << std::endl;
		}
	}

	void print() const
	{
		for (size_t i = 0; i < _size; i++)
		{
			std::cout << "numbers[" << std::setw(3) << std::setfill(' ') << i << "] = " << static_cast<int>(_array[i]) << std::endl;
		}
	}

class OutOfBoundsException : public std::exception
{
	public:
		const char *what() const throw()
		{
			return "Array index out of bounds";
		}
};

};

#endif
