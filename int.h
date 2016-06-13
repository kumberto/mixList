#pragma once
#include "objectList.h"

class Int : public ObjectList
{
	private:
		int number_;
	public:
		Int(int number);
		~Int();
		int getIntValue() const;
		void print() const;
		std::string type() const;
		std::string ToString();
};
