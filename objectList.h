#pragma once

class ObjectList {
	public:
		ObjectList();
		virtual ~ObjectList() = 0;
		virtual int getIntValue() const;
		virtual double getDoubleValue()const;
		virtual std::string getStringValue() const;
		virtual void print() const = 0;
};