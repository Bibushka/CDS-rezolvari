// P3.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <list>
#include <memory>
using namespace std;

class Integer {
public:
	virtual int getValue() const = 0;
	virtual	void print(int position) {cout << position << " " << this->getValue() << " " << this << endl;}
};

class A : public Integer {
public:
	A(int value) {negativNumber = value;}
	int getValue() const {return negativNumber;}
private:
	int negativNumber;
};

class B : public Integer {
public:
	B(int value) {positivNumber = value;}
	int getValue() const {return positivNumber;}
private:
	int unsigned positivNumber;
};


void createList(list<unique_ptr<Integer>>& objectList)
{
	for (int i = 1; i <= 5; i++)
	{
		objectList.push_front(make_unique<A>(i-6));
		objectList.push_back(make_unique<B>(i));
	}	
}

void printObjects(list<unique_ptr<Integer>>& objectList)
{
	int counter = 0;
	for (unique_ptr<Integer> const& object : objectList) 
	{
		counter++;
		object->print(counter);
	}
}

void removeObjectFromPosition(list<unique_ptr<Integer>>& objectList)
{
	list<unique_ptr<Integer>>::iterator it;
	for (it = objectList.begin(); it != objectList.end(); ++it)
		if (it == next(objectList.begin(),1) || it == prev(objectList.end(),2)) 
			it = objectList.erase(it);
}


int main()
{
	list<unique_ptr<Integer>> objectList;
	createList(objectList);
	printObjects(objectList);
	removeObjectFromPosition(objectList);
	printObjects(objectList);
	std::getchar();
	return 0;
}


	/*
	Se cere sa se construiasca o singura lista folosind  std::list  in care sa se pastreze elemente de tipul A si elemente de tipul B. Nu se accepta crearea unei liste de pointeri.

	Se populeaza lista cu urmatoarele elemente: -1, -2 , -3 , -4 , -5, 1, 2 , 3, 4, 5. Unde numerele negative sint pastrare in instante de tipul class A si numerele positive sint de tipul class B.

	a. Ce modificare trebuie facuta la clasa A si B pentru a permite pastrarea in aceeasi lista.
	b. Afiseaza lista sub forma:

	pozitie  (valoare membru negativ sau pozitiv) [ adresa memorie element lista ]
	pozitie  (valoare membru negativ sau pozitiv) [ adresa memorie element lista ]
	. . .


	c. Sterge al II-lea si penultimul element din lista intr-o singura parcurgere a listei folosind instructiunea  for .
	d. Afiseaza lista in formatul de la pct b.
	*/