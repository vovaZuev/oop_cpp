#pragma once
#include "Element.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr);
	~Iterator();
	// Operators
	Iterator& operator++();
	Iterator operator++(int);
	bool operator == (const Iterator& other) const;
	bool operator != (const Iterator& other) const;
	const Element* operator -> () const;
	Element* operator -> ();
	const int& operator*() const;
	int& operator*();
};