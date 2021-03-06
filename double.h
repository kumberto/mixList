#pragma once
#include "objectList.h"

class Double: public ObjectList {
	private:
		double number_;
		Double(const Double&);
		Double& operator=(const Double&);
	public:
		Double(double number);
		~Double();
		double getDoubleValue() const;
		void print() const;
		std::string type() const;
		std::string ToString();
};