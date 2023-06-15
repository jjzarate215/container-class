// Jon Zarate
// ID: 1871142
// Assignment #6
// Submission Date: 12/18/2022
//
//
// Program Description:
// Integer Container class defined
// in namespace CS52 that has similar
// behavior to std::vector

#include <iostream>
#include <string>
#include <exception>
#include "Container.h"

// Default constructor
CS52::Container::Container() {}

// Overloaded constructor
CS52::Container::Container(int size, int int_value)
{
	_size = size;
	_capacity = size;
	_data = new int[_capacity];

	for (int i = 0; i < _size; i++)
	{
		_data[i] = int_value;
	}
}

// Copy constructor
CS52::Container::Container(const Container& that)
{
	this->_size = that._size;
	this->_capacity = that._capacity;
	

	if (that._data != nullptr)
	{
		this->_data = new int[this->_capacity];
		for (int i = 0; i < _size; i++)
			this->_data[i] = that._data[i];
	}
}

CS52::Container::~Container()
{
	delete[] _data;
}

// Returns a reference to the element at index i
// throws a string if i is out-of-bounds
int& CS52::Container::at(int i) const throw(std::string)
{
	std::string message = "out-of-bounds";

	if (i > _size - 1)
		throw message;
	else
		return _data[i];
}

// Erases the elements of the Container but does not change capacity
void CS52::Container::clear()
{
	for (int i = 0; i < _size; i++)
		_data[i] = 0;
		
	_size = 0;

}

// Returns pointer to the first element in the Container
int* CS52::Container::data() const
{
	return this->_data;
}

// If Container is empty return true, else false
bool CS52::Container::empty() const
{
	if (_size == 0)
		return true;
	else
		return false;
}

// Deletes the element at the end of the Container
void CS52::Container::pop_back()
{
	_data[_size - 1] = 0;
	_size--;
}

// Returns the number of elements in the Container
int CS52::Container::size() const
{
	return _size;
}

// Returns the allocated storage for the Container
int CS52::Container::capacity() const
{
	return _capacity;
}

// Returns the type name "Container"
std::string CS52::Container::type() const
{
	std::string data_type = "Container";
	return data_type;
}

// Add an element to the end of the Container
void CS52::Container::push_back(int element)
{
	if (_size == _capacity)
	{
		if (_capacity == 0)
			_capacity++;

		if (_data == nullptr)
			_data = new int[_capacity];

		_capacity *= 2;

		int* temp = new int[_capacity];

		for (int i = 0; i < _size; i++)
			temp[i] = _data[i];

		temp[_size] = element;
		delete[] _data;
		_data = temp;
		_size++;
	}
	else if (_size < _capacity) {
		_data[_size] = element;
		_size++;
	}
}

// Overloaded [] operator
int& CS52::Container::operator [] (int index)
{
	if (_size != 0)
		return _data[index];
}

// Overloaded = operator
CS52::Container& CS52::Container::operator =(const Container& a)
{
	this->_size = a._size;
	this->_capacity = a._capacity;
	this->_data = new int[this->_capacity];
	for (int i = 0; i < a._size; i++)
		this->_data[i] = a._data[i];
	return *this;
}

// Overloaded stream insertion operator
std::ostream& CS52::operator << (std::ostream&, Container& a)
{
	for (int i = 0; i < a._size; i++)
		std::cout << a._data[i] << " ";
	return std::cout;
}

// Overloaded + operator
CS52::Container CS52::Container::operator +(const Container& rhs)
{
	if (this->_size > rhs._size) {
		this->_size = rhs._size;
	}
	if (this->_capacity > rhs._capacity)
		this->_capacity = rhs._capacity;
	CS52::Container temp;
	temp._size = this->_size;
	temp._capacity = this->_capacity;
	temp._data = new int[this->_capacity];
	for (int i = 0; i < temp._size; i++)
		temp._data[i] = this->_data[i] + rhs._data[i];
	return temp;
		
}

