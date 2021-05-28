#include "BList.h"

// ************************* Getters & Setters ************************************* //
const Element* BList::get_head() const
{
	return Head;
}
const Element* BList::get_tail() const
{
	return Tail;
}
const int BList::get_size() const
{
	return size;
}
void BList::set_head(Element* head)
{
	this->Head = head;
}
void BList::set_tail(Element* tail)
{
	this->Tail = tail;
}
// **************************** Constructors **************************************** //
// Default Constructor
BList::BList()
{
	this->Head = nullptr;
	this->Tail = nullptr;
	this->size = 0;
	std::cout << "LConstructor:\t" << this << std::endl;
}
// Copy Constructor
BList::BList(const BList& other)
{

}
// Move Constructor
BList::BList(const BList&& other)
{

}
// Destructor
BList::~BList()
{
	std::cout << "LDestructor:\t" << this << std::endl;
}
// ******************************* Methods ****************************************** //
	// Remove elements
void BList::pop_back()
{

}
void BList::pop_front()
{

}
void BList::erase(int index)
{

}
// Add elements
void BList::push_back(int data)
{
	if (Tail == nullptr)
	{
		push_front(data);
		return;
	}
	Element* New = new Element(data, Tail, nullptr);
	Tail->pNext = New;
	Tail = New;
	++size;
}
void BList::push_front(int data)
{
	Head = new Element(data, nullptr, Head);
	if (!size)
		Tail = Head;
	++size;
}
void BList::insert(int data, int index)
{
	if (index < 0 || index >= size) return;
	if (index == 0)
	{
		push_front(data);
		return;
	}
	if (index <= size / 2)
	{
		Element* temp = Head;
		Element* New = new Element(data);
		for (int i{}; i < index - 1; ++i)
		{
			temp = temp->pNext;
		}
		New->pNext = temp->pNext;
		New->pPrev = temp;
		temp->pNext->pPrev = New;
		temp->pNext = New;
	}
	else
	{
		Element* temp = Tail;
		Element* New = new Element(data);
		for (int i{}; i < size - index; ++i)
		{
			temp = temp->pPrev;
		}
		New->pNext = temp->pNext;
		New->pPrev = temp;
		temp->pNext->pPrev = New;
		temp->pNext = New;
	}
	++size;
}
void BList::print()
{
	for (Element* temp = Head; temp; temp = temp->pNext)
	{
		std::cout << temp->Data << " ";
	}
	std::cout << std::endl;
}