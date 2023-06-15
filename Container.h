//
// Container class definition
// Inherits from Sequence.h
// defined in namespace CS52
//

#pragma once

#include "Sequence.h"
using namespace std;
namespace CS52 {
	class Container : public Sequence {
	public:
		Container();                       // Default constructor
		Container(int size, int int_val);  // Overloaded constructor
		Container(const Container&);       // Copy constructor
		~Container();                      // Destructor

		// Returns a reference to the element at index i
		// throws a string if i is out-of-bounds
		int& at(int i) const throw(std::string);

		
		// Erases the elements of the Container but does not change capacity
		void clear();

		// Returns pointer to the first element in the Container
		int* data() const;

		// If Container is empty return true, else false
		bool empty() const;

		// Deletes the element at the end of the Container
		void pop_back();
		
		// Add an element to the end of the Container
		void push_back(int element);

		// Returns the number of elements in the Container
		int size() const override;
		
		// Returns the allocated storage for the Container
		int capacity() const override;

		// Returns the type name "Container"
		std::string type() const override;

		// Overloaded operators
		int& operator [] (int index);		// [] array syntax

		Container& operator = (const Container&); // copy assignment

		// overloaded + operator to add two Containers
		// m = [1, 2, 3], n = [1, 2, 3]; o = m + n = [2, 4, 6]
		//
		// if rhs.size() < this -> size()
		// return Container of rhs.size(),
		// otherwise return Container this-size();
		//

		Container operator+(const Container& rhs);

		// Overloaded stream insertion operator
		friend std::ostream& operator<< (std::ostream&, Container&);
		
	private:

		int _size = 0;
		int _capacity = 0;
		int* _data = nullptr;
	};//Container
}//namespace

