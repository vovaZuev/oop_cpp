#include <iostream>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::list;

template <typename T> void list_properties(const list<T>& lst);
template <typename T> void print_list(const list<T>& lst);

int main()
{
	setlocale(LC_ALL, "");
	// list - это контейнер, который хранит данные в виде двусв€зного списка
	list<int> lst = {3, 5, 8, 13, 21, 34};
	list_properties(lst);
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