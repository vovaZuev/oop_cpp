#include <iostream>
using namespace std;

class Weapon
{
public:
	virtual void damage() = 0; // Чисто виртуальный метод
};

class Firearms : public Weapon
{
	double caliber;
	int capacity;
	double range;
};

class Pistol : public Firearms
{
	string model;
public:
	void damage()
	{
		cout << "*-----" << endl;
	}
};

int main()
{
	Pistol de;
	de.damage();
}