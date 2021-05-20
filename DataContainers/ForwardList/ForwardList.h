#pragma once
#include "Iterator.h"
#include "Element.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class ForwardList;
ForwardList operator + (const ForwardList& left, const ForwardList& right);
ostream& operator << (ostream& os, ForwardList& obj);

class ForwardList
{
	unsigned int size;
	Element* Head; // указатель на начальный элемент списка
public:
	const unsigned int get_size() const;
	const Element* get_head() const;
	Iterator begin();
	Iterator end();
	// CONSTRUCTORS
	ForwardList();
	// Initializer list constructor
	ForwardList(const std::initializer_list<int>il);
	// Copy Constructor
	ForwardList(const ForwardList& other);
	// Move Constructor
	ForwardList(ForwardList&& other);
	~ForwardList();
	// OPERATORS
	ForwardList& operator = (const ForwardList& other);
	ForwardList& operator = (ForwardList&& other);
	int& operator [] (int index);
	// Adding elements
	void push_front(int Data);
	void push_back(int Data);
	void insert(int Data, int index);
	// Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);
	// Methods
	void print() const;
};