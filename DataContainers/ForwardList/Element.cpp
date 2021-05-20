#include "Element.h"

const int Element::get_data() const
{
	return Data;
}
const Element* Element::get_pnext() const
{
	return pNext;
}
Element* Element::get_pnext()
{
	return pNext;
}
Element::Element(int Data, Element* pNext) : Data(Data), pNext(pNext)
{
	count++;
	//cout << "ElementConstructor:\t" << this << endl;
}
Element::~Element()
{
	count--;
	//cout << "ElementDestructor:\t" << this << endl;
}