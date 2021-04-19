#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#define delim "---------------------------------------------------------------"

using namespace std;
using std::cin;
using std::cout;
using std::endl;

class String;
String operator + (const String& left, const String& right);
ostream& operator << (ostream& os, const String& obj);
istream& operator >> (istream& is, String& obj);

class String
{
	char* str; // Указатель на строку в динамической памяти
	int size; // Размер строки в байтах
public:
	const char* get_str() const;
	char* get_str();
	int get_size() const;
	// Constructors
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other);
	~String();
	// Operators
	String& operator=(const String& other);
	String& operator = (String&& other);
	String& operator+=(const String& other);
	char& operator[](int index);
	const char& operator[](int index) const;
	// Methods
	void print() const;
};