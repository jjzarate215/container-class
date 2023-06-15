# container-class
The Container class inherits an abstract base class named Sequence. Container class behaves similar to std::vector class.

The Container object is meant to be used as std::vector class is used and contains functions
similar to std::vector class that allow user to copy, assign, add, and print container
elements

/////////////////////////////////////////////////////////
The Container class contains the following functions

clear()
erases the elements of the Container but does not change capacity

data()
returns pointer to the first element in the Container

empty()
If Container is empty returns true, else false

pop_back()
Deletes the element at the end of the Container

push_back(int element)
add an element to the end of the Container

size()
returns the number of elements in the Container

capacity()
returns the allocated storage for the Container

///////////////////////////////////////////////////////////
The Container class has the following overloaded operators

[]
indexes array element

=
copies container

+
adds elements of two containers

