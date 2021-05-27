#include "BiDiList.h"

// Getters & Setters
const Element* BiDiList::get_head() const
{
	return Head;
}
const Element* BiDiList::get_tail() const
{
	return Tail;
}
const int BiDiList::get_size() const
{
	return size;
}
Element* BiDiList::set_head(Element* head)
{
	this->Head = head;
}
Element* BiDiList::set_tail(Element* tail)
{
	this->Tail = tail;
}