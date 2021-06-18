#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

#define tab '\t'
#define delimiter "\n*********************************************************************\n\n"

int main()
{
	string input_file = "original.txt";
	
	ifstream fin;
	fin.open(input_file);
	if (fin.is_open())
	{
		string output_file = "final.txt";
		ofstream fout;
		fout.open(output_file);
		while (!fin.eof())
		{
			string ip{};
			string mac{};
			while (fin >> ip >> mac)
			{
				fout << mac << tab << ip << endl;
			}
		}
		fout << delimiter;
		fin.clear();
		fin.seekg(0);
		while (!fin.eof())
		{
			string ip{};
			string mac{};
			int i = 1;
			while (fin >> ip >> mac)
			{
				replace(mac.begin(), mac.end(), '-', ':');
				fout << "host 201-" << i << endl;
				fout << "{\n";
				fout << "\thardware ethernet\t" << mac << ";\n";
				fout << "\tfixed-address\t\t" << ip << ";\n";
				fout << "}\n\n";
				++i;
			}
		}
		fout.close();
	}
	else
	{
		cout << "Error\n";
	}
	fin.close();
	system("notepad final.txt");
}