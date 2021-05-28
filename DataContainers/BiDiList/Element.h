#pragma once
#include <iostream>

class Element
{
	int Data;
	Element* pPrev;
	Element* pNext;
	static int count;
public:
	// ************************* Getters & Setters ************************************* //
	const int get_data() const;
	const Element* get_pPrev() const;
	const Element* get_pNext() const;
	void set_data(int data);
	void set_pPrev(Element* pPrev);
	void set_pNext(Element* pNext);
	// **************************** Constructors **************************************** //
	// Data Constructor
	Element(const int data, Element* pPrev = nullptr, Element* pNext = nullptr);
	// Destructor
	~Element();

	friend class BiDiList;
};