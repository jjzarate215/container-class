//
// Sequence.h parent class
// defined in namespace CS52
//

#pragma once

#include <string>

//Sequence class Declaration
namespace CS52 {
	class Sequence
	{
	public:
		virtual int size() const = 0;
		virtual int capacity() const = 0;
		virtual std::string type() const = 0;
		virtual ~Sequence() {}
		
	};
}