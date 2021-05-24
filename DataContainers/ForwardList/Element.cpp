#include "Element.h"

template <typename T> const T Element<T>::get_data() const
{
	return Data;
}
template <typename T> const Element<T>* Element<T>::get_pnext() const
{
	return pNext;
}
template <typename T> Element<T>* Element<T>::get_pnext()
{
	return pNext;
}
template <typename T> Element<T>::Element(T Data, Element* pNext) : Data(Data), pNext(pNext)
{
	count++;
	//cout << "ElementConstructor:\t" << this << endl;
}
template <typename T> Element<T>::~Element()
{
	count--;
	//cout << "ElementDestructor:\t" << this << endl;
}