// 
// Driver Code
// Test Container class
//


#include <iostream>
#include <string>
#include "Container.h"



void info(CS52::Container& c) {
	std::cout << "Size is: " << c.size() << "\n";
	std::cout << "Capacity is: " << c.capacity() << "\n";
	std::cout << "Contents: ";
	for (int i = 0; i < c.size(); i++) {
		std::cout << c[i] << " ";
	}
	std::cout << "\n";
}// info


int main() {

	// default constructor , push_back , at methods
	std::cout << "//default constructor, push_back, at \nCS52::Container a;\n";
	CS52::Container a;
	std::cout << "\na.push_back(10); a.push_back(88)\n";
	a.push_back(10); a.push_back(88);
	std::cout << "a.at(0) = 99;\n";
	a.at(0) = 99;
	info(a);
	std::cout << a.data();

	//b
	std::cout << "\n// overloaded constructor, [] op, at, empty, clear, exception handling: at\nCS52::Container b(2 ,5);\n";
	
	CS52::Container b(2, 5);
	std::cout << "b is " << b << "\n";
	
	std::cout << "\n//Add more elements to b\n";
	std::cout << "b.push_back(10); b.push_back(2);\n";
	std::cout << "b.push_back(99); b.push_back( -5);\n";
	b.push_back(10); b.push_back(2);
	b.push_back(99); b.push_back(-5);

	std::cout << "\n//array index [] and at()\n";
	std::cout << "b[0] = 25; b[1] = 1;\n";
	b[0] = 25; b[1] = 1;
	std::cout << "b.at(0); b.at(1);\n";
	std::cout << b.at(0) << " " << b.at(1) << "\n";

	std::cout << "\n\n//empty method, size, and capacity\n";
	std::cout << "b.empty() " << (b.empty() ? " True" : "False") << "\n";
	std::cout << "b.clear()\n";
	b.clear();
	info(b);
	std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";

	std::cout << "\n\n//Exception handling:";
	try {
		std::cout << "\nb.at(9) = ";
		std::cout << b.at(9);
	}
	catch (std::string msg) { std::cerr << "\n" << msg << std::endl; }
	
	
	//c
	std::cout << "\n//copy constructor, copy assignment, pop_back,\n//capacity, size\nCS52::Container c(b);\n";
	std::cout << "\n//Add more elements to b\n";
	std::cout << "b.push_back(11); b.push_back(7);\n";
	std::cout << "b. push_back(3); b.push_back(23);\n";
	b.push_back(11); b.push_back(7);
	b.push_back(3); b.push_back(23);
	CS52::Container c(b);
	info(c);

	//d
	std::cout << "\n//copy assignment\n";
	CS52::Container d;
	d = c;
	std::cout << "CS52::Container d = c; " << "\n";
	std::cout << "d is " << d << "\n";
	std::cout << "\n//size vs capacity()\n";
	std::cout << "d.size() is " << d.size() << "\n";
	std::cout << "d.capacity() is " << d.capacity() << "\n";

	std::cout << "\n//pop_back()\n";
	std::cout << "d.pop_back();d.pop_back();\n";
	d.pop_back(); d.pop_back();

	std::cout << "\n//size vs capacity\n";
	std::cout << "d.size() is " << d.size() << "\n";
	std::cout << "d.capacity() is " << d.capacity() << "\n";
	

	
	// Test overloaded + operator
	CS52::Container m(5, 3);
	CS52::Container n(3, 0);
	n[0] = 55; n[1] = 100; n[2] = 500;
	CS52::Container o = m + n;
	std::cout << "Test overloaded + operator\n";
	std::cout << "m = [3, 3, 3, 3, 3], n = [55, 100, 500]\n";
	std::cout << "o = m + n = [" << o << "]\n";

	const int SIZE = 2;

	CS52::Sequence* sequence[SIZE];
	sequence[0] = new CS52::Container(2, 1);
	sequence[1] = new CS52::Container(5, 3);

	// Print out the type and length of each Sequence element
	std::cout << "\nTest polymorphism\n";

	for (int i = 0; i < SIZE; i++)
	{
		std::cout << "Sequence [" << i << "]" << " is a " << sequence[i]->type()
			<< ": " << *(dynamic_cast <CS52::Container*> (sequence[i])) << "\n";
	}

	for (int i = 0; i < 2; i++)
		delete sequence[i];

	char stop; std::cin >> stop; return 0;
	
}// main -- end of example driver code
