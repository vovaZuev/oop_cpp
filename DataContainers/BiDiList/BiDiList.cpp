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
// **************************** Constructors **************************************** //
// Default Constructor
BiDiList::BiDiList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->size = 0;
	std::cout << "LConstructor:\t" << this << std::endl;
}
// Copy Constructor
BiDiList::BiDiList(const BiDiList& other)
{

}
// Move Constructor
BiDiList::BiDiList(const BiDiList&& other)
{

}
// Destructor
BiDiList::~BiDiList()
{
	std::cout << "LDestructor:\t" << this << std::endl;
}
// ******************************* Methods ****************************************** //
	// Remove elements
void BiDiList::pop_back()
{

}
void BiDiList::pop_front()
{

}
void BiDiList::erase(int index)
{

}
// Add elements
void BiDiList::push_back(int data)
{

}
void BiDiList::push_front(int data)
{

}
void BiDiList::insert(int data, int index)
{

}