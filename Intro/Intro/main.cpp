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

	/*Point()
	{
		x = y = 0;
		cout << "DefConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "Single argument constructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstrustor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor:\t" << this << endl;
	}

	// Operators
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	Point& operator += (const Point& other)
	{
		this->x += other.x;
		this->y += other.y;
		cout << "Operator += " << this << endl;
		return *this;
	}

	Point& operator ++ ()
	{
		this->x++;
		this->y++;
		cout << "Prefix increment " << this << endl;
		return *this;
	}

	Point operator ++(int)
	{
		Point old = *this;
		this->x++;
		this->y++;
		cout << "Postfix increment " << this << endl;
		return old;
	}

	/*Point operator + (const Point& other) const
	{
		Point result;
		result.x = this->x + other.x;
		result.y = this->y + other.y;
		cout << "Operator + " << this << endl;
		return result;
	}*/

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

double Distance(Point a, Point b);

Point operator + (const Point& left, const Point& right)
{
	Point res;
	res.set_x(left.get_x() + right.get_x());
	res.set_y(left.get_y() + right.get_y());
	cout << "Global plus" << endl;
	return res;
}

Point operator - (const Point& left, const Point& right)
{
	Point res(left.get_x() - right.get_x(), left.get_y() - right.get_y());
	cout << "Global minus" << endl;
	return res;
}

Point operator * (const Point& left, const Point& right)
{
	cout << "Global mult" << endl;
	return Point(
		left.get_x() * right.get_x(),
		left.get_y() * right.get_y()
	);
}

Point operator / (const Point& left, const Point& right)
{
	cout << "Global divide" << endl;
	return Point(
		left.get_x() / right.get_x(),
		left.get_y() / right.get_y()
	);
}

ostream& operator << (ostream& os, const Point obj)
{
	return os << "X = " << obj.get_x() << "\t" << "Y = " << obj.get_y();
}

int main()
{
	setlocale(LC_ALL, "");
	// Constructors Check
	/*//double ax, ay, bx, by;
	cout << "Введите координаты точки А: "; cin >> ax >> ay;
	Point A(ax, ay);
	A.print();
	/*A.set_x(5);
	A.set_y(17);
	cout << A.get_x() << "\t" << A.get_y() << endl;

	Point* Pa = &A;
	cout << Pa->get_x() << "\t" << Pa->get_y() << endl;
	cout << "Введите координаты точки B: "; cin >> bx >> by;
	Point B(bx, by);
	B.print();

	Point C = 5; // Single argument constructor
	C.print();
	Point D(8); // Single argument constructor;
	D.print();
	Point E{ 13 }; // Single argument constructor
	E.print();
	cout << int{} << endl; // Default value for int

	Point F = C; // Copy constructor
	C.print();
	Point G;
	G = F; // Copy assignment operator


	 Тест на метод distance

	cout << "Метод: Расстояние от точки А до точки B равно " << A.distance(B) << endl;

	 Тест на функцию Distance

	//cout << "Функция: Расстояние между точками А и B равно " << Distance(A, B) << endl;*/
	/*int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point();*/
	/*Point A(2, 3);
	Point B(1, 4);
	Point C = A + B;
	C.print();
	(A - B).print();
	(A * B).print();
	(A / B).print();*/
	Point A(2, 3);
	Point B(3, 4);
	A += B; // Неявный вызов оператора
	A.print();
	A.operator+=(B); // Явный вызов оператора
	A.print();
	operator/(A, B).print(); // Явный вызов глобального оператора
	++A;
	A.print();
	A++;
	A.print();
	cout << A << endl;
}

double Distance(Point a, Point b)
{
	return sqrt((a.get_x() - b.get_x()) * (a.get_x() - b.get_x()) + (a.get_y() - b.get_y()) * (a.get_y() - b.get_y()));
}