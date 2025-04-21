#include <iostream>
using namespace std;

int main() {
	auto* p_int = new int{10}; // allocate space for an int and initialize with 10
	cout << "int value = " << *p_int << ": location = " << p_int << endl;
	cout << "size of p_int = " << sizeof(p_int);
	cout << ": size of *p_int = " << sizeof(*p_int) << endl;
	delete p_int;
	cout << endl;

	auto* p_double = new double{20.}; // allocate space for a double and initialize with 20.
	cout << "double value = " << *p_double << ": location = " << p_double << endl;
	cout << "size of p_double = " << sizeof(p_double);
	cout << ": size of *p_double = " << sizeof(*p_double) << endl;
	delete p_double;

	return EXIT_SUCCESS;
}

