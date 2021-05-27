#include "Element.h"
#include "BiDiList.h"
#include <iostream>

int Element::count{};

int main()
{
	Element* elm = new Element(2);
	std::cout << elm->get_data() << std::endl;
}