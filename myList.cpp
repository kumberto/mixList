#include <iostream>
#include <string>
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
	List *temp = new List();
	temp->head = list.head;
	temp->tail = list.tail;
}

List * List::operator=(const List & list)
{
	List *temp = new List();
	temp->head = list.head;
	temp->tail = list.tail;
	return temp;
}


List::~List()
{
	while(head)
	{
		Node *temp = head->next;
		delete head->object;
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
	Node* temp = head;
	
	while (temp != nullptr)
	{
		if (temp->object->getIntValue() == number)
		{
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			else
				tail = tail->prev;
			if (temp->prev != nullptr)
				temp->prev->next = temp->next;
			else
				head = head->next;
			delete temp->object;
			temp->object = nullptr;
			delete temp;
			temp = nullptr;
		}
		else
		{
			temp = temp->next;
		}

	}
}

void List::remove(double number)
{
	Node* temp = head;

	while (temp != nullptr)
	{
		if (temp->object->getDoubleValue() == number)
		{
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			else
				tail = tail->prev;
			if (temp->prev != nullptr)
				temp->prev->next = temp->next;
			else
				head = head->next;
			delete temp->object;
			delete temp;
			temp = nullptr;
		}
		else
		{
			temp = temp->next;
		}
	}
}

void List::remove(std::string str)
{
	Node* temp = head;
	while (temp != nullptr)
	{
		if (temp->object->getStringValue() == str)
		{
			if (temp->next != nullptr)
				temp->next->prev = temp->prev;
			else
				tail = tail->prev;
			if (temp->prev != nullptr)
				temp->prev->next = temp->next;
			else
				head = head->next;
			delete temp->object;
			delete temp;
			temp = nullptr;
		}
		else
		{
			temp = temp->next;
		}
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
	temp = nullptr;
	delete temp;
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