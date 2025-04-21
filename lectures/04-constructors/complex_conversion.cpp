#include <iostream>
using namespace std;

//	A constructor that is not declared with the specifier explicit is called a
//	converting constructor.

//	Unlike explicit constructors, which are only considered during direct
//	initialization (which includes explicit conversions such as static_cast),
//	converting constructors are also considered during copy initialization, as
//	part of user-defined conversion sequence.

//	It is said that a converting constructor specifies an implicit conversion
//	from the types of its arguments (if any) to the type of its class. Note that
//	non-explicit user-defined conversion function also specifies an implicit
//	conversion. Implicitly-declared and user-defined non-explicit copy
//	constructors and move constructors are converting constructors. 

class Complex {

public:
//	explicit
	Complex(double re = 0, double im = 0) : re{re}, im{im} {
		cout << "Complex()" << endl;
	}

	void print(const string& name) const {
		cout << name << ": <" << re << ", " << im << ">" << endl;
	}

	friend Complex add(Complex a, Complex b);

private:
	double re, im;
};

Complex add (Complex a, Complex b) {
	return Complex {a.re + b.re, a.im + b.im};
}

int main () {
	double d{4.5};
	Complex z1 {1.5, 5.3}, z2{1.2, 3.4};

	z1.print("z1");
	z2.print("z2");
	cout << "d:  " << d << endl;
	cout << endl;

	Complex z3 = add (z1, z2);
	z3.print("z1 + z2");
	cout << endl;

	z3 = add(z1, d); // Error if ctor explicit
//	z3 = add(z1, Complex(d)); // OK
	z3.print("z1 + d");
	cout << endl;

	z3 = add(d, z2); // Error if ctor explicit
//	z3 = add(Complex(d), z2); // OK
	z3.print("d + z2");

	return EXIT_SUCCESS;
}

