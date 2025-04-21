#include <iostream>
using namespace std;

double sqr1 (const double&);	//	possible type conversion
double sqr2 (double&);	//	no type conversion

int main() {
	int n = 2;
	float f = 2.0f;
	double d = 2.0;

	cout << "sqr1(n)    = " << sqr1(n) << endl;
	cout << "sqr1(f)    = " << sqr1(f) << endl;
	cout << "sqr1(d)    = " << sqr1(d) << endl;
	cout << "sqr1(2)    = " << sqr1(2) << endl;
	cout << "sqr1(2.0f) = " << sqr1(2.0f) << endl;
	cout << "sqr1(2.0)  = " << sqr1(2.0) << endl;
	cout << endl;

	cout << "sqr2(d)    = " << sqr2(d) << endl;
//	cout << sqr2(n) << endl;
//	cout << sqr2(f) << endl;
//	cout << sqr2(2) << endl;
//	cout << sqr2(2.0f) << endl;
//	cout << sqr2(2.0) << endl;

	return EXIT_SUCCESS;
}

double sqr1 (const double& x) { return x*x; }
double sqr2 (double& x) { return x*x; }

