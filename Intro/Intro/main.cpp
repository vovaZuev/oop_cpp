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
};

int main()
{
	setlocale(LC_ALL, "");
	Point A;
	A.set_x(5);
	A.set_y(17);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* Pa = &A;
	cout << Pa->get_x() << "\t" << Pa->get_y() << endl;
}