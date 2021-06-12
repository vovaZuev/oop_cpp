#include <iostream>
#include <map>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::map;
using std::list;
using std::pair;

#define spc ' '
#define delim "/n**************************************/n/n"

int main()
{
	setlocale(LC_ALL, "");
	/*map<int, string> week =
	{
		pair<int, string> (0, "Sunday"),
		pair<int, string> (1, "Monday"),
		pair<int, string> (2, "Tuesday"),
		pair<int, string> (3, "Wednesday"),
		pair<int, string> (4, "Thursday"),
		pair<int, string> (5, "Friday"),
		pair<int, string> (6, "Saturday")
	};
	for (map<int, string>::iterator it = week.begin(); it != week.end(); it++)
	{
		cout << it->first << spc << it->second << endl;
	}*/
	map<string, list<string>> dictionary =
	{
		pair<string, list<string>>("finite", {"ограниченный", "имеющий предел"}),
		pair<string, list<string>>("adjacent", {"примыкающий", "смежный", "соседний"}),
		pair<string, list<string>>("plot", {"карта", "план", "график", "сюжет"}),
		pair<string, list<string>>("incident", {"Случай", "случайность", "происшествие"}),
		pair<string, list<string>>("splice", {"соединение", "сращивание"})
	};
	dictionary["space"].assign({"пространство", "космос", "пробел"});
	for (map<string, list<string>>::iterator it = dictionary.begin(); it != dictionary.end(); it++)
	{
		for (list<string>::iterator lit = it->second.begin(); lit != it->second.end(); lit++)
		{
			cout << it->first << spc << *lit << endl;
		}
	}
}