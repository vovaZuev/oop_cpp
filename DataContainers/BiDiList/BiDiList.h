#pragma once
#include "Element.h"
#include <iostream>

class BiDiList
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
	BiDiList();
	// Copy Constructor
	BiDiList(const BiDiList& other);
	// Move Constructor
	BiDiList(const BiDiList&& other);
	// Destructor
	~BiDiList();
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