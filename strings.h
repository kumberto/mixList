#pragma once
#include <string>
#include "objectList.h"


class String : public ObjectList {
	private:
		std::string str_;
	public:
		String(std::string str);
		~String();
		std::string getStringValue() const;
		void print();
};