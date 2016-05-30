#include <iostream>
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

void Double::print()
{
	std::cout << number_;
}