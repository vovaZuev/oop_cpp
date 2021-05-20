#include "Iterator.h"

Iterator(Element* Temp = nullptr) : Temp(Temp)
{
	cout << "IConstructor:\t" << this << endl;
}
~Iterator()
{
	cout << "IDestructor:\t" << this << endl;
}
// Operators
Iterator& operator++()
{
	Temp = Temp->pNext;
	return *this;
}
Iterator operator++(int)
{
	Iterator old = *this;
	Temp = Temp->pNext;
	return old;
}
bool operator == (const Iterator& other) const
{
	return this->Temp == other.Temp;
}
bool operator != (const Iterator& other) const
{
	return this->Temp != other.Temp;
}
const Element* operator -> () const
{
	return Temp;
}
Element* operator -> ()
{
	return Temp;
}
const int& operator*() const
{
	return Temp->Data;
}
int& operator*()
{
	return Temp->Data;
}