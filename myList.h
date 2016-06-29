#pragma once
#include "objectList.h"
#include <string>

struct Node{
	ObjectList *object;
	Node *next;
	Node *prev;
	Node();
	~Node();
	Node(const Node& other);
	Node& operator=(const Node& other);
};

class List{
	private:
		Node *head;
		Node *tail;
		void add_element(ObjectList *object);
		void removeElement(ObjectList *object);
	public:
		List();
		List(const List &list);
		List& operator=(const List &list);
		~List();
		void add(int number);
		void add(double number);
		void add(std::string str);
		void remove(int number);
		void remove(double number);
		void remove(std::string str);
		void removeAll();
		void popBack();
		ObjectList* getObject(int i) const;
		int size() const;
		void printAll() const;
};
