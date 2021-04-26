#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::string;

class Shape
{
	string color;
public:
	Shape(const string& color)
	{
		this->color = color;
	}
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual void draw() const = 0;
};

class Square : public Shape
{
	double side;
public:
	double get_side() const
	{
		return side;
	}
	void set_side(double side)
	{
		if (side > 0)
			this->side = side;
		else
			this->side = 1;
	}
	Square(double side, const string& color = "white") : Shape(color)
	{
		set_side(side);
	}
	~Square() {}
	// Methods
	double area() const
	{
		return side * side;
	}
	double perimeter() const
	{
		return side * 4;
	}
	void draw() const
	{
		for (int i = 0; i < side; i++)
		{
			for (int j = 0; j < side; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

class Rectangle : public Shape
{
	double sideA;
	double sideB;
public:
	double get_sideA() const
	{
		return sideA;
	}
	double get_sideB() const
	{
		return sideB;
	}
	void set_sideA(double sideA)
	{
		if (sideA > 0)
			this->sideA = sideA;
		else
			this->sideA = 1;
	}
	void set_sideB(double sideB)
	{
		if (sideB > 0)
			this->sideB = sideB;
		else
			this->sideB = 1;
	}
	Rectangle(double sideA, double sideB, const string& color = "green") : Shape(color)
	{
		set_sideA(sideA);
		set_sideB(sideB);
	}
	~Rectangle(){}
	// Methods
	double area() const
	{
		return sideA * sideB;
	}
	double perimeter() const
	{
		return sideA * 2 + sideB * 2;
	}
	void draw() const
	{
		for (int i = 0; i < sideA; i++)
		{
			for (int j = 0; j < sideB; j++)
			{
				cout << "* ";
			}
			cout << endl;
		}
	}
};

int main()
{
	setlocale(LC_ALL, "");
	Square sq(5);
	cout << "Area: " << sq.area() << endl;
	cout << "Perimeter: " << sq.perimeter() << endl;
	sq.draw();
	Rectangle rec(5, 7);
	cout << "Area: " << rec.area() << endl;
	cout << "Perimeter: " << rec.perimeter() << endl;
	rec.draw();

}