#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

class String
{
	char* str; // Указатель на строку в динамической памяти
	int size; // Размер строки в байтах
public:
	const char* get_str() const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size() const
	{
		return size;
	}
	// Constructors
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << (size == 80 ? "Default " : "Size ") << "Constructor:\t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		strcpy(this->str, str);
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "Copy Constructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}
	// Operators
	String& operator=(const String& other)
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
	String& operator+=(const String& other)
	{
		int oldsize = size;
		char* temp = new char[oldsize] {};
		strcpy(temp, this->str);
		delete[] this->str;
		this->size += other.size - 1;
		this->str = new char[size] {};
		strcpy(this->str, temp);
		delete[] temp;
		for (int i = oldsize - 1; i < size - 1; i++)
		{
			this->str[i] = other[i - oldsize + 1];
		}
		//cout << "Operator +=: " << this << endl;
		return *this;
	}
	char& operator[](int index)
	{
		return str[index];
	}
	const char& operator[](int index) const
	{
		return str[index];
	}
	// Methods
	void print() const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};

ostream& operator << (ostream& os, const String& obj)
{
	return os << obj.get_str();
}

String operator + (const String& left, const String& right)
{
	String result = left.get_size() + right.get_size() - 1;
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

#define delim "---------------------------------------------------------------"

int main()
{
	setlocale(LC_ALL, "");
	/*String str;
	str.print();
	String str2 = "Hello";
	str2.print();
	cout << str2 << endl;
	String str3 = str2;
	cout << "str3:\t" << str3 << endl;
	String str4;
	str4 = str3;
	cout << "str4:\t" << str4 << endl;*/
	/*String str1 = "Hello";
	String str2;
	str1 = str1;
	cout << str1 << endl;
	cout << str2 << endl;*/
	String str1 = "Hello";
	String str2 = "world";
	String str3 = str1 + str2;
	cout << delim << endl;
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
	cout << "Operator '=' test: " << str3 << endl;
	cout << "Operator '[]' test: " << str1[1] << endl;
	cout << "Operator '+=' test: " << (str1 += str3) << endl;
	cout << delim << endl;
}