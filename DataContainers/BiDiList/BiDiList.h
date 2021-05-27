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
};