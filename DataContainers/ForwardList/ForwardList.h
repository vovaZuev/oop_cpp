#pragma once
#include "Iterator.h"
#include "Element.h"
#include <iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> class ForwardList;
template <typename T> ForwardList<T> operator + (const ForwardList<T>& left, const ForwardList<T>& right);
template <typename T> ostream& operator << (ostream& os, ForwardList<T>& obj);

template <typename T> class ForwardList
{
	unsigned int size;
	Element<T>* Head; // указатель на начальный элемент списка
public:
	const unsigned int get_size() const;
	const Element<T>* get_head() const;
	Iterator<T> begin();
	Iterator<T> end();
	// CONSTRUCTORS
	ForwardList();
	// Initializer list constructor
	ForwardList(const std::initializer_list<T>il);
	// Copy Constructor
	ForwardList(const ForwardList& other);
	// Move Constructor
	ForwardList(ForwardList&& other);
	~ForwardList();
	// OPERATORS
	ForwardList<T>& operator = (const ForwardList<T>& other);
	ForwardList<T>& operator = (ForwardList<T>&& other);
	T& operator [] (int index);
	// Adding elements
	void push_front(T Data);
	void push_back(T Data);
	void insert(T Data, int index);
	// Removing elements
	void pop_front();
	void pop_back();
	void erase(int index);
	// Methods
	void print() const;
};