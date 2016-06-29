#include <iostream>
#include <sstream>
#include "int.h"

Int::Int( int number)
:number_(number)
, ObjectList()
{
	std::cout << "Int Constructor" << std::endl;
}

Int::~Int()
{
	std::cout << "Int destructor" << std::endl;
}

int Int::getIntValue() const
{
	return number_;
}

void Int::print() const
{
	std::cout << number_;
}

std::string Int::type() const
{
	return "int";
}

std::string Int::ToString()
{
	std::ostringstream ost;
	ost << number_;
	std::string s_num = ost.str();
	std::cout << s_num << std::endl;
	return s_num;
}
