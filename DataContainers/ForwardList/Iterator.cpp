#include "Iterator.h"

Iterator::Iterator(Element* Temp) : Temp(Temp)
{
	cout << "IConstructor:\t" << this << endl;
}
Iterator::~Iterator()
{
	cout << "IDestructor:\t" << this << endl;
}
// Operators
Iterator& Iterator::operator++()
{
	Temp = Temp->pNext;
	return *this;
}
Iterator Iterator::operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
bool Iterator::operator == (const Iterator& other) const
{
	return this->Temp == other.Temp;
}
bool Iterator::operator != (const Iterator& other) const
{
	return this->Temp != other.Temp;
}
const Element* Iterator::operator -> () const
{
	return Temp;
}
Element* Iterator::operator -> ()
{
	return Temp;
}
const int& Iterator::operator*() const
{
	return Temp->Data;
}
int& Iterator::operator*()
{
	return Temp->Data;
}