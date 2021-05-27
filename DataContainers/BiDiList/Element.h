#pragma once
#include <iostream>

class Element
{
	int Data;
	Element* pPrev;
	Element* pNext;
public:
	// Getters & Setters
	const int get_data() const;
	const Element* get_pPrev() const;
	const Element* get_pNext() const;
	int set_data(int data);
	Element* set_pPrev(Element* pPrev);
	Element* set_pNext(Element* pNext);
};