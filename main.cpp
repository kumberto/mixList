#include <iostream>
#include "mylist.h"


int main()
{
	int d;
	
	{
		List list;
		list.add("string");
		list.getObject(1)->print();
		list.add(45);
		list.getObject(2)->print();
		list.add(4.4);
		list.getObject(3)->print();
		list.printAll();
		list.remove(45);
		
		list.printAll();
		list.remove("string");
		list.printAll();
		list.remove(4.4);
		list.printAll();
	}
	std::cin >> d;
	return 0;
}
