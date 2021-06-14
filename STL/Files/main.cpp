#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;

//#define WRITE_TO_FILE
//#define READ_FROM_FILE
#define COPY_FILE

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

#ifdef WRITE_TO_FILE
	ofstream fout;
	fout.open("file.txt", ios_base::app);
	fout << "Hello world ";
	fout.close();
	system("notepad file.txt");
#endif // WRITE_TO_FILE
#ifdef READ_FROM_FILE
	ifstream fin;
	fin.open("file.txt");
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			//fin >> buffer;
			fin.getline(buffer, n);
			cout << buffer << endl;
		}
	}
	else
	{
		cout << "File not found" << endl;
	}
	fin.close();
#endif // READ_FROM_FILE
#ifdef COPY_FILE
	ofstream fout;
	ifstream fin;
	fout.open("copy.txt");
	fin.open("file.txt");
	const int n = 256;
	char buffer[n] = {};
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.getline(buffer, n);
			fout << buffer << endl;
		}
	}
	else
	{
		cout << "Error" << endl;
	}
	fout.close();
	fin.close();
	system("notepad copy.txt");
#endif // COPY_FILE


}