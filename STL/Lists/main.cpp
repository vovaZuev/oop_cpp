#include <iostream>
#include <list>
#include <forward_list>
using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::forward_list;

#define delim "\n********************************************************\n\n"
#define spc ' '
//#define LIST
#define FORWARD_LIST

template <typename T> void list_properties(const list<T>& lst);
template <typename T> void print_list(const list<T>& lst);
template <typename T> void reverse_print_list(const list<T>& lst);

int main()
{
	setlocale(LC_ALL, "");
	// list - это контейнер, который хранит данные в виде двусв€зного списка
#ifdef LIST
	list<int> lst = { 3, 5, 8, 13, 21, 34 };
	/*list_properties(lst);
	print_list(lst);
	lst.push_back(55);
	lst.push_front(2);
	list_properties(lst);
	print_list(lst);

	int index, value;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	list<int>::iterator position = lst.begin();
	for (int i = 0; i < index; i++) position++;
	lst.insert(position, value);
	print_list(lst);
	reverse_print_list(lst);*/
	lst.resize(20);
	for (list<int>::iterator it = lst.begin(); it != lst.end(); it++)
	{
		*it = rand() % 10;
	}
	cout << endl;
	print_list(lst);
	cout << delim;
	lst.sort();
	print_list(lst);
	cout << delim;
	lst.unique();
	lst.reverse();
	print_list(lst);
	cout << delim;
#endif // LIST
#ifdef FORWARD_LIST
	forward_list<int> flst = { 2, 3, 5, 8, 13 };
	flst.push_front(34);
	for (forward_list<int>::iterator it = flst.begin(); it != flst.end(); it++)
	{
		cout << *it << spc;
	}
	cout << endl;
	int index, value;
	cout << "¬ведите индекс добавл€емого элемента: "; cin >> index;
	cout << "¬ведите значение добавл€емого элемента: "; cin >> value;
	forward_list<int>::iterator position = flst.before_begin();
	for (int i = 0; i < index; i++) position++;
	flst.insert_after(position, value);
	for (int i : flst) cout << i << spc; cout << endl;
#endif
}

template <typename T> void list_properties(const list<T>& lst)
{
	cout << "Size:     " << lst.size() << endl;
	cout << "Max Size: " << lst.max_size() << endl;
}
template <typename T> void print_list(const list<T>& lst)
{
	for (list<int>::const_iterator it = lst.begin(); it != lst.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}
template <typename T> void reverse_print_list(const list<T>& lst)
{
	for (list<int>::const_reverse_iterator it = lst.crbegin(); it != lst.crend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}