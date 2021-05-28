#include "Element.h"
#include "BList.h"
#include <iostream>

int Element::count{};

int main()
{
	int n = 5;
	BList* list = new BList();
	for (int i{}; i < n; ++i)
	{
		list->push_front(rand() % 100);
	}
	list->print();
	std::cout << list->get_size() << std::endl;
	list->push_front(99);
	std::cout << list->get_size() << std::endl;
	list->print();
	list->push_back(77);
	std::cout << list->get_size() << std::endl;
	list->print();
	list->insert(88, 2);
	std::cout << list->get_size() << std::endl;
	list->print();
	list->insert(55, 4);
	std::cout << list->get_size() << std::endl;
	list->print();
}