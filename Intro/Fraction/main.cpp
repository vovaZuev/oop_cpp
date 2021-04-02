#include <iostream>
using namespace std;

class Fraction;
Fraction operator * (Fraction left, Fraction right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const
	{
		return integer;
	}
	int get_numerator() const
	{
		return numerator;
	}
	int get_denominator() const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator)
			this->denominator = denominator;
		else
			this->denominator = 1;
	}
	
	// Constructors
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Default Constructor: " << this << endl;
	}
	Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "Single Argument Constructor: " << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor " << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->integer = integer;
		this->numerator = numerator;
		this->set_denominator(denominator);
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Constructor: " << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor " << this << endl;
	}
	// Operators
	Fraction& operator = (const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copy Assignment: " << this << endl;
		return *this;
	}
	Fraction& operator *= (const Fraction& other)
	{
		return *this = *this * other;
	}
	// Methods
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
		/*Fraction copy = *this;
		copy.integer += copy.numerator / copy.denominator;
		copy.numerator %= copy.denominator;
		return copy;*/
	}
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
		/*Fraction copy = *this;
		copy.numerator += copy.integer * copy.denominator;
		copy.integer = 0;
		return copy;*/
	}
	void print() const
	{
		cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
	}
};

Fraction operator + (Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;
}
Fraction operator - (Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_integer(left.get_integer() - right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() - left.get_denominator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	return result;
}
Fraction operator * (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
Fraction operator / (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();
}

ostream& operator<< (ostream& os, const Fraction& obj)
{
	if(obj.get_integer())
		os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())
			os << "(";
		os << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())
			os << ")";
	}
	else if (obj.get_integer() == 0)
		os << 0;
	return os;
}

int main()
{
	setlocale(LC_ALL, "");
	// Constructors check
	/*Fraction A;
	A.print();
	cout << A << endl;
	double b = 5;
	cout << b << endl;
	Fraction B = 5;
	B.print();
	cout << B << endl;
	Fraction C(1, 2);
	C.print();
	cout << C << endl;
	Fraction D(3, 4, 5);
	D.print();
	cout << D << endl;*/
	// Methods check
	/*Fraction A(11, 4);
	cout << A << " = " << A.to_proper() << endl;
	cout << A << " = " << A.to_improper() << endl;*/
	// Operators check
	Fraction A(11, 4);
	Fraction B(5, 6, 7);
	cout << (A *= B) << endl;
}