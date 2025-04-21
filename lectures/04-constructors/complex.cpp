#include <iostream>
using namespace std;

class Complex {

public:
	Complex(double re, double im) : re{re}, im{im} {}

	void print(const string& name) const {
		cout << name << ": <" << re << ", " << im << ">" << endl;
	}
	friend Complex add(Complex a, Complex b);
	friend Complex add(Complex a, double  b);
	friend Complex add(double  a, Complex b);

private:
	double re, im;
};

Complex add(Complex a, Complex b) {
	cout << "add(Complex, Complex)" << endl;
	return {a.re + b.re, a.im + b.im};
}

Complex add(Complex a, double b) {
	cout << "add(Complex, double)" << endl;
	return {a.re + b, a.im};
}

Complex add(double a, Complex b) {
	cout << "add(double, Complex)" << endl;
	return {a + b.re, b.im};
}

int main () {
	double d = 4.5;
	Complex z1(1.5, 5.3), z2(1.2, 3.4);

	cout << "d:  " << d << endl;
	z1.print("z1");
	z2.print("z2");
	cout << endl;

	Complex z3 = add (z1, z2);
	z3.print("z1 + z2");
	z3 = add (z1, d);
	z3.print("z1 + d");
	z3 = add (d, z2);
	z3.print("d + z2");

	return EXIT_SUCCESS;
}

