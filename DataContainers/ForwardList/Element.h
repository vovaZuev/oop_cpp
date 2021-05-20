#pragma once
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Element
{
	int Data; // значение эл-та
	Element* pNext; // указатель на следующий элемент
	static int count;
public:
	const int get_data() const;
	const Element* get_pnext() const;
	Element* get_pnext();
	Element(int Data, Element* pNext = nullptr);
	~Element();
	friend class ForwardList;
	friend class Iterator;
};