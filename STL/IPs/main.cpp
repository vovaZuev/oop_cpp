#include <iostream>
#include <fstream>

using namespace std;

#define spaces "        "

int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("original.txt");
	fout.open("final.txt");
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string left{};
			string right{};
			while (fin >> left >> right)
			{
				fout << right << spaces << left << endl;
			}
		}
	}
	else
	{
		cout << "Error\n";
	}
	fout.close();
	fin.close();
	system("notepad final.txt");
}