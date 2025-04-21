#include <iostream> 
#include <cmath> 
using namespace std; 

double harmonic_mean(double a, double b);
double geometric_mean(double a, double b);

int main() {
	double x, y;
	cout << "Enter two numbers: ";
	try {
		while (cin >> x >> y) {
			double hm = harmonic_mean(x, y);
			double gm = geometric_mean(x, y);
			cout << "Harmonic mean from " << x << " and "
				 << y << " = " << hm << endl;
			cout << "Geometric mean from " << x << " and "
				 << y << " = " << gm << endl;
			cout << "Enter next two numbers <q - quit>: ";
		}
	} catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
	return 0;
}

// invalid_argument : public logic_error : public exception

double harmonic_mean(double a, double b) {
	if(fabs(a + b) < 1e-10) 
		throw invalid_argument("Invalid argument: harmonic_mean(): a cannot be equal to -b");
	return 2.0 * a * b / (a + b);
}

double geometric_mean(double a, double b) {
	if (a < 0 || b < 0) 
		throw invalid_argument("Invalid argument: geometric_mean(): values must be > 0");
	return sqrt(a * b); 
}

