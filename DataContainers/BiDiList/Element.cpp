#include "Element.h"

// Getters & Setters
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
int Element::set_data(int data)
{
	this->Data = data;
}
Element* Element::set_pPrev(Element* pPrev)
{
	this->pPrev = pPrev;
}
Element* Element::set_pNext(Element* pNext)
{
	this->pNext = pNext;
}