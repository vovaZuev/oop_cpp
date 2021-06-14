#include <Windows.h>
#include <string>
#include <iostream>
#include <map>
#include <forward_list>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::list;
using std::forward_list;
using std::pair;
using std::string;

#define spc ' '
#define tab '	'
#define delim "/n**************************************/n/n"

int menu(map<string, forward_list<string>>& base);
void printBase(const map<string, forward_list<string>>& base);
void addCrime(map<string, forward_list<string>>& base);
void crimes_of(string id, const map<string, forward_list<string>>& base);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, forward_list<string>> base =
	{
		pair<string, forward_list<string>>("м234кр777", {"Проезд на красный", "Превышение скорости"}),
		pair<string, forward_list<string>>("м124кр777", {"Парковка в неположенном месте"}),
		pair<string, forward_list<string>>("м555кр777", {"Превышение скорости"}),
		pair<string, forward_list<string>>("н555кр178", {"Проезд на красный", "Пересечение сплошной"})
	};
	/*printBase(base);
	addCrime(base);
	printBase(base);
	string id;
	cout << "Введите номер автомобиля: "; cin >> id;
	crimes_of(id, base);*/
	menu(base);
}
int menu(map<string, forward_list<string>>& base)
{
	cout << "1 - Вывод всей базы\n2 - Вывод информации по номеру\n3 - Вывод по диапазону номеров\n4 - Добавление нарушения\n5 - Выход\n";
	int choice;
	cin >> choice;
	string id;
	switch (choice)
	{
	case 1:
		printBase(base); break;
	case 2:
		cout << "Введите номер машины: "; cin >> id;
		crimes_of(id, base);
		break;
	case 4:
		addCrime(base); break;
	case 5:
		return choice;
	default:
		cout << "Недопустимое действие\n";
	}
	menu(base);
	return choice;
}
void printBase(const map<string, forward_list<string>>& base)
{
	for (map<string, forward_list<string>>::const_iterator it = base.begin(); it != base.end(); it++)
	{
		cout << it->first << ":\t";
		for (forward_list<string>::const_iterator lit = it->second.begin(); lit != it->second.end(); lit++)
		{
			cout << *lit << ", ";
		}
		cout << "\b\b;\n";
	}
}
void addCrime(map<string, forward_list<string>>& base)
{
	string id;
	string crime;
	cout << "Введите номер автомобиля: "; cin >> id;
	cin.ignore();
	cout << "Введите нарушение: "; getline(cin, crime);
	base[id].push_front(crime);
}
void crimes_of(string id, const map<string, forward_list<string>>& base)
{
	if (base.find(id) != base.end())
	{
		map<string, forward_list<string>> ::const_iterator criminal = base.find(id);
		if (criminal != base.end())
		{
			cout << "Список нарушений " << id << ":\n";
			for (forward_list<string>::const_iterator it = criminal->second.begin(); it != criminal->second.end(); it++)
			{
				cout << *it << "\n";
			}
		}
	}
}