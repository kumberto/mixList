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
	Node *ptrNode = list.head;
	while (ptrNode != nullptr)
	{
		if (ptrNode->object->type() == "int")
		{
			add(ptrNode->object->getIntValue());
		}
		else if (ptrNode->object->type() == "double")
		{
			add(ptrNode->object->getDoubleValue());
		}
		else
		{
			add(ptrNode->object->getStringValue());
		}
		ptrNode = ptrNode->next;
	}
}

List& List::operator=(const List & list)
{
	if (this == &list) return *this;
	
	removeAll();

	Node *ptrNode = list.head;
	while (ptrNode != nullptr)
	{
		if (ptrNode->object->type() == "int")
		{
			add(ptrNode->object->getIntValue());
		}
		else if (ptrNode->object->type() == "double")
		{
			add(ptrNode->object->getDoubleValue());
		}
		else
		{
			add(ptrNode->object->getStringValue());
		}
		ptrNode = ptrNode->next;
	}
	return *this;
}


List::~List()
{
	while(head)
	{
		Node *ptrNode = head->next;
		delete head;
		head = ptrNode;
	}
}

void List::add_element(ObjectList *object)
{
	Node *ptrNode = new Node;
	ptrNode->next = NULL;
	ptrNode->object = object;
	
	if ( head != NULL )
	{
		ptrNode->prev = tail;
		tail->next = ptrNode;
		tail = ptrNode;
	}
	else
	{
		ptrNode->prev = NULL;
		head = ptrNode;
		tail = ptrNode;
	}
}

void List::removeElement(ObjectList * object)
{
	Node *ptrNode = head;
	while (ptrNode != nullptr)
	{
		if (ptrNode->object->ToString() == object->ToString() && ptrNode->object->type() == object->type())
		{
			if (ptrNode->next != nullptr)
				ptrNode->next->prev = ptrNode->prev;
			else
				tail = tail->prev;
			if (ptrNode->prev != nullptr)
				ptrNode->prev->next = ptrNode->next;
			else
				head = head->next;
			delete ptrNode;
			break;
		}
		else
		{
			ptrNode = ptrNode->next;
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
	removeElement(intObject);
}

void List::remove(double number)
{
	Double* doubleObject = new Double(number);
	removeElement(doubleObject);
}

void List::remove(std::string str)
{
	String* stringObject = new String(str);
	add_element(stringObject);
}

void List::removeAll()
{
	while(head != nullptr)
	{
		removeElement(head->object);
	}
}

void List::popBack()
{
	Node *ptrNode = tail;
	tail = tail->prev;
	tail->next = nullptr;
	delete ptrNode;
}

ObjectList* List::getObject(int i) const
{
	if ( size() >= i )
	{
		Node *ptrNode = head;
		while (i > 1)
		{
			i -= 1;
			ptrNode = ptrNode->next;
		}
		return ptrNode->object;
	}
	return nullptr;
}

int List::size() const
{
	int amount = 0;
	Node* ptrNode = head;
	while (ptrNode != nullptr)
	{
		amount += 1;
		ptrNode = ptrNode->next;
	}
	return amount;
}

void List::printAll() const
{
	Node *ptrNode = head;
	while( ptrNode != NULL )
	{
		ptrNode->object->print();
		std::cout << " ";
		ptrNode = ptrNode->next;
	}
}

Node::Node()
{}

Node::~Node()
{
	delete object;
}

Node::Node(const Node & other)
{
	this->next = other.next;
	this->prev = other.prev;
	this->object = other.object;
}

Node & Node::operator=(const Node & other)
{
	Node *ptrNode = this;
	this->next = other.next;
	this->prev = other.prev;
	this->object = other.object;
	delete ptrNode;
	return *this;
}
