#include "Fraction.h"

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
	/*Fraction A(11, 4);
	Fraction B(33, 12);*/
	/*A *= B;
	cout << A << endl;
	A /= B;
	cout << A << endl;
	cout << A - A << endl;*/
	/*for (Fraction i(3, 4); i.get_integer() < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;*/
	/*cout << (Fraction(1, 2) == Fraction(3, 7)) << endl;
	cout << (Fraction(1, 2) != Fraction(3, 7)) << endl;*/
	Fraction A = (Fraction)5;
	cout << A << endl;
	Fraction B(3, 4, 5);
	double b = (double)B;
	cout << b << endl;
	Fraction C = 2.33;
	cout << C << endl;
}