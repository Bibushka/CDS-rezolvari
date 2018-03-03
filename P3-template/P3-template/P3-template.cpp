// P3-template.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <list>

template <class Base>
class Integer : Base {
public:
	Integer(int value) : Base(value) { }
	void print(int position) const
	{
		std::cout << position << " " << this->getValue() << " " << this;
	}
};

class A {
public:
	A(int value) {
		negativ = value;
	}

	int getValue() const {
		return negativ;
	}

private:
	int negativ;
};

class B {
public:
	B(int value) {
		positiv = value;
	}

	int getValue() const {
		return positiv;
	}

private:
	unsigned int positiv;
};

int main()
{
	std::list<Integer<A>> objectlist(10);
	for (int i = 1; i <= 5; i++)
		objectlist.push_back(Integer<A>(-i));
	for (const auto& i : objectlist)
	{
		i.print(0);
	}
    return 0;
}

