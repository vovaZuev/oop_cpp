#include <iostream>
using namespace std;

class Point
{
	double x;
	double y;
public:
	double get_x() const
	{
		return x;
	}
	double get_y() const
	{
		return y;
	}
	void set_x(double value)
	{
		this->x = value;
	}
	void set_y(double value)
	{
		this->y = value;
	}

	// Constructors

	Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Methods
	void print() const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Point A;
	/*A.set_x(5);
	A.set_y(17);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* Pa = &A;
	cout << Pa->get_x() << "\t" << Pa->get_y() << endl;*/
	A.print();
	Point B(3, 2);
	B.print();
}