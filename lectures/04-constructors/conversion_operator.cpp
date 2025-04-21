#include <iostream>
#include <cmath>
using namespace std;

class Complex {

public:
	explicit Complex(double re = 0, double im = 0) : re{re}, im{im} {} // double -> Complex

//	explicit
	operator double() const { // Complex -> double
		cout << "operator double()" << endl;
		return re;
	}

	void print() const {
		cout << "<" << re << ", " << im << ">" << endl; 
	}

private:
	double re, im;
};

int main () {
	Complex z(9., 5.3);
	cout << "z: ";
	z.print();

//	double d = sqrt((double)z);	//	double d = sqr(z.operator double())
	double d = sqrt(z);	//	double d = sqr(z.operator double())
	cout << "sqrt(z): " << d << endl;

	return EXIT_SUCCESS;
}

