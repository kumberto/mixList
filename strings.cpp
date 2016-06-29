#include <iostream>
#include "strings.h"

String::String(std::string str)
: str_(str)
,ObjectList()
{
	std::cout << "String Constructor" << std::endl;
}

String::~String()
{
	std::cout << "String dustructor" << std::endl;
}

std::string String::getStringValue() const
{
	return str_;
}

void String::print() const
{
	std::cout << str_;
}

std::string String::type() const
{
	return "string";
}
