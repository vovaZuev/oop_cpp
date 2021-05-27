#include "BiDiList.h"

// ************************* Getters & Setters ************************************* //
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
void BiDiList::set_head(Element* head)
{
	this->Head = head;
}
void BiDiList::set_tail(Element* tail)
{
	this->Tail = tail;
}