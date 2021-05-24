#pragma once
#include <iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> class Iterator;
template <typename T> class ForwardList;
template <typename T> class Element
{
	T Data; // значение эл-та
	Element* pNext; // указатель на следующий элемент
	static int count;
public:
	const T get_data() const;
	const Element* get_pnext() const;
	Element* get_pnext();
	Element(T Data, Element* pNext = nullptr);
	~Element();
	friend class ForwardList<T>;
	friend class Iterator<T>;
};