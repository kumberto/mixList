#include <iostream>
#include <string>
#include <functional>
#include "mylist.h"
#include "int.h"
#include "double.h"
#include "strings.h"

List::List()
:head(NULL)
,tail(NULL)
{}

List::List(const List & list)
{
	this->head = list.head;
	this->tail = list.tail;
}

List& List::operator=(const List & list)
{
	if (this != &list)
	{
		this->head = list.head;
		this->tail = list.tail;
	}
	return *this;
}


List::~List()
{
	while(head)
	{
		Node *temp = head->next;
		delete head;
		head = temp;
	}
}

void List::add_element(ObjectList *object)
{
	Node *temp = new Node;
	temp->next = NULL;
	temp->object = object;
	
	if ( head != NULL )
	{
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
	}
	else
	{
		temp->prev = NULL;
		head = temp;
		tail = temp;
	}
}

void List::remove_element(ObjectList * object)
{
	Node *temp = head;
	while (temp != nullptr)
	{
		if (temp->object->ToString() == object->ToString() && temp->object->type() == object->type())
		{
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			else
				tail = tail->prev;
			if (temp->prev != nullptr)
				temp->prev->next = temp->next;
			else
				head = head->next;
			delete temp;
			break;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void List::add(int number)
{
	Int* intObject = new Int(number);
	add_element(intObject);
}

void List::add(double number)
{
	Double* doubleObject = new Double(number);
	add_element(doubleObject);
}

void List::add(std::string str)
{
	String* stringObject = new String(str);
	add_element(stringObject);
}

void List::remove(int number)
{
	Int* intObject = new Int(number);
	remove_element(intObject);
}

void List::remove(double number)
{
	Double* doubleObject = new Double(number);
	remove_element(doubleObject);
}

void List::remove(std::string str)
{
	String* stringObject = new String(str);
	add_element(stringObject);
}

void List::remove_all()
{

	while(head != nullptr)
	{
		remove_element(head->object);
	}
}

ObjectList* List::getObject(int i) const
{
	if ( size() >= i )
	{
		Node *temp = head;
		while (i > 1)
		{
			i -= 1;
			temp = temp->next;
		}
		return temp->object;
	}
	return nullptr;
}

int List::size() const
{
	int amount = 0;
	Node* temp = head;
	while (temp != nullptr)
	{
		amount += 1;
		temp = temp->next;
	}
	return amount;
}

void List::printAll() const
{
	Node *buffer = head;
	std::cout << std::endl;
	while( buffer != NULL )
	{
		buffer->object->print();
		std::cout << " ";
		buffer = buffer->next;
	}
	std::cout << std::endl;
}

Node::~Node()
{
	delete object;
}
