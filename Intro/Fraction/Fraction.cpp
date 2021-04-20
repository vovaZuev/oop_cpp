#include "Fraction.h"

int Fraction::get_integer() const
{
	return integer;
}
int Fraction::get_numerator() const
{
	return numerator;
}
int Fraction::get_denominator() const
{
	return denominator;
}
void Fraction::set_integer(int integer)
{
	this->integer = integer;
}
void Fraction::set_numerator(int numerator)
{
	this->numerator = numerator;
}
void Fraction::set_denominator(int denominator)
{
	if (denominator)
		this->denominator = denominator;
	else
		this->denominator = 1;
}

// Constructors
Fraction::Fraction()
{
	this->integer = 0;
	this->numerator = 0;
	this->denominator = 1;
#ifdef DEBUG
	cout << "Default Constructor: " << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int integer)
{
	this->integer = integer;
	this->numerator = 0;
	this->denominator = 1;
#ifdef DEBUG
	cout << "Single Argument Constructor: " << this << endl;
#endif // DEBUG

}
Fraction::Fraction(double dec)
{
	integer = (int)dec;
	double dp = dec - integer + 1e-12;
	denominator = 1e+9;
	numerator = dp * denominator;
	Fraction::reduce();
}
Fraction::Fraction(int numerator, int denominator)
{
	this->integer = 0;
	this->numerator = numerator;
	this->set_denominator(denominator);
#ifdef DEBUG
	cout << "Constructor " << this << endl;
#endif // DEBUG

}
Fraction::Fraction(int integer, int numerator, int denominator)
{
	this->integer = integer;
	this->numerator = numerator;
	this->set_denominator(denominator);
}
Fraction::Fraction(const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
#ifdef DEBUG
	cout << "Copy Constructor: " << this << endl;
#endif // DEBUG

}
Fraction::~Fraction()
{
#ifdef DEBUG
	cout << "Destructor " << this << endl;
#endif // DEBUG

}
// Operators
Fraction& Fraction::operator = (const Fraction& other)
{
	this->integer = other.integer;
	this->numerator = other.numerator;
	this->denominator = other.denominator;
	cout << "Copy Assignment: " << this << endl;
	return *this;
}
Fraction& Fraction::operator *= (const Fraction& other)
{
	return *this = *this * other;
}
Fraction& Fraction::operator /= (const Fraction& other)
{
	return *this = *this / other;
}
// Increment Decrement
Fraction& Fraction::operator ++ () // Prefix increment
{
	integer++;
	return *this;
}
Fraction& Fraction::operator -- () // Prefix decrement
{
	integer--;
	return *this;
}
Fraction Fraction::operator ++ (int) // Prefix increment
{
	Fraction old = *this;
	integer++;
	return old;
}
Fraction Fraction::operator -- (int) // Prefix increment
{
	Fraction old = *this;
	integer--;
	return old;
}
// Type cast operators
Fraction::operator int() const
{
	return integer;
}
Fraction::operator double() const
{
	return integer + numerator / (double)denominator;
}
// Methods
Fraction& Fraction::to_proper()
{
	integer += numerator / denominator;
	numerator %= denominator;
	return *this;
	/*Fraction copy = *this;
	copy.integer += copy.numerator / copy.denominator;
	copy.numerator %= copy.denominator;
	return copy;*/
}
Fraction& Fraction::to_improper()
{
	numerator += integer * denominator;
	integer = 0;
	return *this;
	/*Fraction copy = *this;
	copy.numerator += copy.integer * copy.denominator;
	copy.integer = 0;
	return copy;*/
}
Fraction& Fraction::reduce()
{
	if (!numerator) return *this;
	int more, less, rest;
	// Определяем, что больше - числитель или знаменатель.
	if (numerator > denominator)
		more = numerator, less = denominator;
	else
		less = numerator, more = denominator;
	// Вычисляем НОД
	do
	{
		rest = more % less;
		more = less;
		less = rest;
	} while (rest);
	int GCD = more; // Greatest Common Divisor
	// Сокращаем дробь.
	numerator /= GCD;
	denominator /= GCD;
	return *this;
}
Fraction Fraction::inverted() const
{
	Fraction inverted = *this;
	inverted.to_improper();
	swap(inverted.numerator, inverted.denominator);
	return inverted;
}
void Fraction::print() const
{
	cout << integer << "(" << numerator << "/" << denominator << ")" << endl;
}


Fraction operator + (Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_integer(left.get_integer() + right.get_integer());
	result.set_numerator(left.get_numerator() * right.get_denominator() + left.get_denominator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	result.to_proper();
	result.reduce();
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
	result.reduce();
	return result;
}
Fraction operator * (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();
}
Fraction operator / (Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	return Fraction(
		left.get_numerator() * right.get_denominator(),
		left.get_denominator() * right.get_numerator()
	).to_proper();*/
	return left * right.inverted();
}

// Comparison operators

bool operator == (Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == left.get_denominator() * right.get_numerator();
}
bool operator != (const Fraction& left, const Fraction& right)
{
	return !(left == right);
}

// Stream operators

ostream& operator<< (ostream& os, const Fraction& obj)
{
	if (obj.get_integer())
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
