#include "String.h"

const char* String::get_str() const
{
	return str;
}
char* String::get_str()
{
	return str;
}
int String::get_size() const
{
	return size;
}
// Constructors
String::String(int size) : size(size), str(new char[size] {})
{
	/*this->size = size;
	this->str = new char[size] {};*/
	cout << (size == 80 ? "Default " : "Size ") << "Constructor:\t" << this << endl;
}
String::String(const char* str) : String(strlen(str) + 1)
{
	/*this->size = strlen(str) + 1;
	this->str = new char[size] {};*/
	strcpy(this->str, str);
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) : String(other.str)
{
	/*this->size = other.size;
	this->str = new char[size] {};*/
	//strcpy(this->str, other.str);
	cout << "Copy Constructor:\t" << this << endl;
}
String::String(String&& other) : size(other.size), str(other.str)
{
	/*this->size = other.size;
	this->str = other.str;*/
	other.str = nullptr;
	cout << "Move Constructor: " << this << endl;
}
String::~String()
{
	delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
}
// Operators
String& String::operator=(const String& other)
{
	//0) Проверить, не является ли другой объект нашим объектом
	if (this == &other) return *this;
	//1) Сначала удаляем старое значение объекта
	delete[] this->str;
	//2) Только потом присваиваем ему новое значение
	this->size = other.size;
	this->str = new char[size] {};
	strcpy(this->str, other.str);
	cout << "Copy Assignment:\t" << this << endl;
	return *this;
}
String& String::operator = (String&& other)
{
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.str = nullptr;
	cout << "Move Assignment: " << this << endl;
	return *this;
}
String& String::operator+=(const String& other)
{
	return *this = *this + other;
}
char& String::operator[](int index)
{
	return str[index];
}
const char& String::operator[](int index) const
{
	return str[index];
}
// Methods
void String::print() const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}

ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}

istream& operator >> (istream& is, String& obj)
{
	return is >> obj.get_str();
}

String operator + (const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	/*for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];*/
	for (int i = 0; i < left.get_size(); i++)
		result[i] = left[i];
	for (int i = 0; i < right.get_size(); i++)
		result[left.get_size() - 1 + i] = right[i];
	return result;
}
