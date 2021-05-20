#include "Element.h"

const int get_data() const
{
	return Data;
}
const Element* get_pnext() const
{
	return pNext;
}
Element* get_pnext()
{
	return pNext;
}
Element(int Data, Element* pNext = nullptr) : Data(Data), pNext(pNext)
{
	count++;
	//cout << "ElementConstructor:\t" << this << endl;
}
~Element()
{
	count--;
	//cout << "ElementDestructor:\t" << this << endl;
}