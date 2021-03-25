#include <iostream>
#include <math.h>
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
	double distance(Point p)
	{
		return sqrt((p.x - this->x) * (p.x - this->x) + (p.y - this->y) * (p.y - this->y));
	}
};

double Distance(Point a, Point b)
{
	return sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
}

int main()
{
	setlocale(LC_ALL, "");
	double ax, ay, bx, by;
	cout << "Введите координаты точки А: "; cin >> ax >> ay;
	Point A(ax, ay);
	A.print();
	/*A.set_x(5);
	A.set_y(17);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* Pa = &A;
	cout << Pa->get_x() << "\t" << Pa->get_y() << endl;*/
	cout << "Введите координаты точки B: "; cin >> bx >> by;
	Point B(bx, by);
	B.print();

	// Тест на метод distance

	cout << "Метод: Расстояние от точки А до точки B равно " << A.distance(B) << endl;

	// Тест на функцию Distance

	cout << "Функция: Расстояние между точками А и B равно " << Distance(A, B) << endl;
}