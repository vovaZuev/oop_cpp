#pragma once
#include <iostream>
using namespace std;

class Fraction;
Fraction operator + (Fraction left, Fraction right);
Fraction operator - (Fraction left, Fraction right);
Fraction operator * (Fraction left, Fraction right);
Fraction operator / (Fraction left, Fraction right);
bool operator == (Fraction left, Fraction right);
bool operator != (const Fraction& left, const Fraction& right);
ostream& operator<< (ostream& os, const Fraction& obj);

class Fraction
{
	int integer;
	int numerator;
	int denominator;
public:
	int get_integer() const;
	int get_numerator() const;
	int get_denominator() const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);

	// Constructors
	Fraction();
	explicit Fraction(int integer);
	Fraction(double dec);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	// Operators
	Fraction& operator = (const Fraction& other);
	Fraction& operator *= (const Fraction& other);
	Fraction& operator /= (const Fraction& other);
	// Increment Decrement
	Fraction& operator ++ ();
	Fraction& operator -- ();
	Fraction operator ++ (int);
	Fraction operator -- (int);
	// Type cast operators
	explicit operator int() const;
	explicit operator double() const;
	// Methods
	Fraction& to_proper();
	Fraction& to_improper();
	Fraction& reduce();
	Fraction inverted() const;
	void print() const;
};


