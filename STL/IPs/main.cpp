#include <iostream>
#include <fstream>

using namespace std;

#define spaces "        "
#define delimiter "\n*********************************************************************\n\n"

int main()
{
	ofstream fout;
	ifstream fin;
	fin.open("original.txt");
	fout.open("final.txt");
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			string ip{};
			string mac{};
			while (fin >> ip >> mac)
			{
				fout << mac << spaces << ip << endl;
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
				for (int i = 0; i < mac.length(); i++)
				{
					if (mac[i] == '-')
						mac[i] = ':';
				}
				fout << "host 201-" << i << endl;
				fout << "{\n";
				fout << "\thardware ethernet\t" << mac << ";\n";
				fout << "\tfixed-address\t\t" << ip << ";\n";
				fout << "}\n\n";
				++i;
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