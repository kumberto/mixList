#include <iostream>
#include <sstream>
#include "double.h"


Double::Double(double number)
:number_(number)
,ObjectList()
{
	std::cout << "Double Constructor" << std::endl;
}

Double::~Double()
{
	std::cout << "Double dustructor" << std::endl;
}

double Double::getDoubleValue() const
{
	return number_;
}

void Double::print() const
{
	std::cout << number_;
}

std::string Double::type() const
{
	return "double";
}

std::string Double::ToString()
{
	std::ostringstream ost;
	ost << number_;
	std::string s_num = ost.str();
	std::cout << s_num << std::endl;
	return s_num;;
}
