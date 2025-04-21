#include <iostream> 
#include <cmath> 
using namespace std; 

double harmonic_mean(double a, double b);

int main() {
	double x, y, z;
	cout << "Enter two numbers: ";
	while (cin >> x >> y) { 
		try {
			z = harmonic_mean(x, y);
			cout << "Harmonic mean of " << x << " and "
			     << y << " = " << z << "\n";
			cout << "Enter next two numbers <q - quit>: ";
		} catch (const char *s) {
			cout << s << "\n"; 
			cout << "Try again: ";
		}
	}
	cout << "Bye!\n"; 
	return 0;
}

double harmonic_mean(double a, double b) {
	if(fabs(a + b) < 1e-10)	//	throw an exception
		throw "harmonic_mean(): a cannot be equal to -b";
	return 2.0 * a * b / (a + b);
}

