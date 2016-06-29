#include <iostream>
#include "mylist.h"


int main()
{
	int d;

	List list;
	
	list.add("string");
	list.add(45);
	list.add(4.4);
	List copy;
	copy.add("int");
	copy.add("double");
	copy.add(89);
	copy.printAll();
	list.popBack();
	list.printAll();
	list = copy;
	copy.printAll();

	std::cin >> d;
	return 0;
}
