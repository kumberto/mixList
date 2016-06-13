#include <iostream>
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
