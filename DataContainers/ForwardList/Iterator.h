#pragma once
#include "Element.h"
#include <iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr);
	~Iterator();
	// Operators
	Iterator& operator++();
	Iterator operator++(int);
	bool operator == (const Iterator& other) const;
	bool operator != (const Iterator& other) const;
	const Element<T>* operator -> () const;
	Element<T>* operator -> ();
	const T& operator*() const;
	T& operator*();
};
