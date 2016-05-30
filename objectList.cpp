#include <iostream>
#include "objectList.h"

ObjectList::ObjectList()
{
	std::cout << "ObjectList Constructor" << std::endl;
}
ObjectList::~ObjectList()
{
	std::cout << "ObjectList destructir" << std::endl;
}

int ObjectList::getIntValue() const
{
	return 0;
}

double ObjectList::getDoubleValue() const
{
	return 0.0;
}

std::string ObjectList::getStringValue() const
{
	return std::string();
}
