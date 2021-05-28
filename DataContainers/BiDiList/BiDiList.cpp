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
	Element* New = new Element(data, Tail, nullptr);
	Tail->pNext = New;
	Tail = New;
	if (!size)
		Head = Tail;
	++size;
}
void BiDiList::push_front(int data)
{
	Element* New = new Element(data, nullptr, Head);
	Head->pPrev = New;
	Head = New;
	if (!size)
		Tail = Head;
	++size;
}
void BiDiList::insert(int data, int index)
{
	if (index < 0 || index >= size) return;
	if (index == 0)
		push_front(data);
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
		std::cout << temp->Data << std::endl;
		Element* New = new Element(data);
		for (int i{}; i < size - index; ++i)
		{
			temp = temp->pPrev;
		}
		std::cout << temp->Data << std::endl;
		/*std::cout << temp->Data << std::endl;
		New->pNext = temp->pNext;
		New->pPrev = temp;
		temp->pNext->pPrev = New;
		temp->pNext = New;*/
	}
	++size;
}
void BiDiList::print()
{
	for (Element* temp = Head; temp; temp = temp->pNext)
	{
		std::cout << temp->Data << " ";
	}
	std::cout << std::endl;
}