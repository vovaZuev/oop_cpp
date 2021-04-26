#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Animal
{
public:
	virtual ~Animal()
	{}
	virtual void sound() const = 0; // чисто виртуальный метод (pure virtual function), благодаря которму класс является абстрактным
};

class Cat : public Animal
{
	// это тоже абстрактный класс
};

class Tiger : public Cat
{
public:
	~Tiger() {}
	void sound() const
	{
		cout << "Ррр" << endl;
	}
};

class HomeCat : public Cat
{
public:
	~HomeCat() {}
	void sound() const
	{
		cout << "Мяу" << endl;
	}
};

class Dog : public Animal
{
public:
	~Dog() {}
	void sound() const
	{
		cout << "Гав" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	// 1. Generalization:
	Animal* zoo[] =
	{
		new HomeCat,
		new Dog,
		new Tiger,
		new Dog,
		new HomeCat
	};
	// 2. Specialisation:
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}