#include "Element.h"
#include "Element.cpp"
#include "Iterator.h"
#include "Iterator.cpp"
#include "ForwardList.h"
#include "ForwardList.cpp"
#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::ostream;

template <typename T> int Element<T>::count = 0; // инициализация статической переменной


#define delim "-----------------------------------------------------"

int main()
{
	setlocale(LC_ALL, "");
	/*int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list1;
	for (int i = 0; i < n; i++)
	{
		list1.push_front(rand() % 100);
	}
	list1.print();
	cout << delim << endl;
	ForwardList list2;
	for (int i = 0; i < n; i++)
	{
		list2.push_front(rand() % 50);
	}
	list2.print();
	cout << delim << endl;
	ForwardList list3 = list1 + list2;
	list3.print();
	cout << delim << endl;
	cout << list3 << endl;*/

	ForwardList<int> list = {3, 5, 8, 13, 21};
	//list.print();
	// Range based for
	for (int i : list)
		cout << i << '\t';
	cout << endl;
	cout << delim << endl;

	ForwardList<double> dfl = { 2.4, 3.7, 5.2, 2.9, 6.7 };
	for (double i : dfl) cout << i << '\t'; cout << endl;
	//cout << dfl << endl;
	cout << delim << endl;

	ForwardList<std::string> stih = {"Хорошо", "живет", "на", "свете", "Винни", "Пух"};
	for (std::string i : stih) cout << i << '\t'; cout << endl;
	//cout << stih << endl;
/*
	cout << "List ready" << endl;
#ifdef TEST_REMOVE
	list.pop_front();
	list.print();
	list.pop_back();
	list.print();
	int i;
	cout << "Введите индекс удаляемого элемента: "; cin >> i;
	list.erase(i);
	list.print();
#endif
#ifdef TEST_ADD
	// push_front & push_back test
	list.push_front(999);
	list.print();
	list.push_back(777);
	list.print();
	// insert test
	list.insert(999, 0);
	list.print();

	cout << "Введите размер списка: "; cin >> n;
	ForwardList list2;
	for (int i = 0; i < n; i++)
	{
		list2.push_front(rand() % 100);
	}
	list2.print();
#endif
*/
	/*int index{};
	cout << "Введите индекс элемента списка для вывода: "; cin >> index;
	try
	{
		cout << index << "-й элемент списка равен " << list[index] << endl;
		list[2] = 99;
		cout << list << endl;
	}
	catch (std::exception e)
	{
		std::cerr << e.what() << endl;
	}*/

}