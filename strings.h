#pragma once
#include <string>
#include "objectList.h"

class String : public ObjectList {
	private:
		std::string str_;
		String(const String&);
		String& operator=(const String&);
	public:
		String(std::string str);
		~String();
		std::string getStringValue() const;
		void print() const;
		std::string type() const;
};