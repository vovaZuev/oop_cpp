#include <Windows.h>
#include <iostream>
#include <string>
#include <map>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::list;
using std::pair;
using std::string;

#define spc ' '
#define tab '	'
#define delim "********************************************************************"

bool searchBase(map<string, list<string>>& base, string number, string crime);
bool findNumber(map<string, list<string>>& base, string number);
void printBase(map<string, list<string>>& base);
void printNumberData(map<string, list<string>>& base, string number);
void searchInsertBase(map<string, list<string>>& base);
void getNumberData(map<string, list<string>>& base);
void getRangeData(map<string, list<string>>& base);
void menu(map<string, list<string>>& finebase);

int main()
{
	SetConsoleCP(1251);// установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251);
	cout << "\n******* БАЗА ДАННЫХ ГАИ ПО ШТРАФНЫМ КВИТАНЦИЯМ *******\n\n";
	
	map<string, list<string>> finebase =
	{
		pair<string, list<string>>("А001ХЕ", {"Езда без прав", "Проезд на запрещающий сигнал светофора", "Превышение скорости"}),
		pair<string, list<string>>("С513ОР", {"Превышение скорости"}),
		pair<string, list<string>>("Е557ОЕ", {"Проезд по выделенной полосе", "Проезд на запрещающий сигнал светофора"}),
		pair<string, list<string>>("Т782КУ", {"Пересечение сплошной линии", "Превышение скорости"}),
		pair<string, list<string>>("О908АК", {"Пересечение двойной сплошной линии", "Наезд на сотрудника ГАИ", "Езда в нетрезвом виде"})
	};
	menu(finebase);
}
bool searchBase(map<string, list<string>>& base, string number, string crime)
{
	bool isfound = false;
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); it++)
	{
		if (it->first == number)
		{
			isfound = true;
			it->second.push_back(crime);
			break;
		}
	}
	return isfound;
}
void printNumberData(map<string, list<string>>& base, string number)
{
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); it++)
	{
		if (it->first == number)
		{
			cout << it->first << tab;
			for (list<string>::iterator lit = it->second.begin(); lit != it->second.end(); lit++)
			{
				cout << *lit << ", ";
			}
			cout << "\b\b;\n";
		}
	}
}
void printBase(map<string, list<string>>& base)
{
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); it++)
	{
		printNumberData(base, it->first);
	}
}
void searchInsertBase(map<string, list<string>>& base)
{
	string number;
	string crime;
	cout << "Введите номер автомобиля: "; cin >> number;
	cin.ignore();
	cout << "Введите правонарушение: "; getline(cin, crime);

	if (!searchBase(base, number, crime))
	{
		base.insert(pair<string, list<string>>(number, { crime }));
	}
	printBase(base);
}
void getNumberData(map<string, list<string>>& base)
{
	string number;
	cout << "Введите номер автомобиля: "; cin >> number;
	if (findNumber(base, number))
		printNumberData(base, number);
	else
		cout << "Такого номера нет в базе.\n";
}
bool findNumber(map<string, list<string>>& base, string number)
{
	bool isfound = false;
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); it++)
	{
		if (it->first == number)
		{
			isfound = true;
			break;
		}
	}
	return isfound;
}
void getRangeData(map<string, list<string>>& base)
{
	string num1, num2;
	cout << "Введите нижнее значение: "; cin >> num1;
	cout << "Введите верхнее значение: "; cin >> num2;
	for (map<string, list<string>>::iterator it = base.begin(); it != base.end(); it++)
	{
		if (it->first >= num1 && it->first <= num2)
			printNumberData(base, it->first);
	}
}
void menu(map<string, list<string>>& finebase)
{
	int choice;
	cout << "1 - Распечатка всей базы\n2 - Распечатка данных по заданному номеру\n3 - Распечатка данных по дапазону\n4 - Поиск и добавление данных\n5 - Выход\n"; cin >> choice;
	
	switch (choice)
	{
	case 1:
		printBase(finebase);
		break;
	case 2:
		getNumberData(finebase);
		break;
	case 3:
		getRangeData(finebase);
		break;
	case 4:
		searchInsertBase(finebase);
		break;
	case 5:
		return;
	default:
		cout << "Введены неверные данные. До свидания\n";
	}
	cout << delim << endl;
	menu(finebase);
}