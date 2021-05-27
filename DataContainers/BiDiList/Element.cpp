#include "Element.h"

// ************************* Getters & Setters ************************************* //
const int Element::get_data() const
{
	return Data;
}
const Element* Element::get_pPrev() const
{
	return pPrev;
}
const Element* Element::get_pNext() const
{
	return pNext;
}
void Element::set_data(int data)
{
	this->Data = data;
}
void Element::set_pPrev(Element* pPrev)
{
	this->pPrev = pPrev;
}
void Element::set_pNext(Element* pNext)
{
	this->pNext = pNext;
}
// **************************** Constructors **************************************** //
// Data Constructor
Element::Element(int data, Element* pPrev, Element* pNext)
{
	this->Data = data;
	this->pPrev = pPrev;
	this->pNext = pNext;
	++count;
	std::cout << "EConstructor:\t" << this << std::endl;
}
// Destructor
Element::~Element()
{
	--count;
	std::cout << "EDestructor:\t" << this << std::endl;
}