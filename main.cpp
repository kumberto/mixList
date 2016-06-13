#include <iostream>
#include "mylist.h"


int main()
{
	int d;

		List list;
		//List copy = list;
		list.add("string");
		list.add(45);
		list.add(4.4);
		
		list.remove_all();
		list.printAll();
	std::cin >> d;
	return 0;
}
