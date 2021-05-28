#pragma once
#include "Element.h"
#include <iostream>

class BList
{
	Element* Head;
	Element* Tail;
	int size;
public:
	// ************************* Getters & Setters ************************************* //
	const Element* get_head() const;
	const Element* get_tail() const;
	const int get_size() const;
	void set_head(Element* head);
	void set_tail(Element* tail);
	// **************************** Constructors **************************************** //
	// Default Constructor
	BList();
	// Copy Constructor
	BList(const BList& other);
	// Move Constructor
	BList(const BList&& other);
	// Destructor
	~BList();
	// ******************************* Methods ****************************************** //
	// Remove elements
	void pop_back();
	void pop_front();
	void erase(int index);
	// Add elements
	void push_back(int data);
	void push_front(int data);
	void insert(int data, int index);
	void print();
};