#include <iostream>
using namespace std;

int ref1() {
	int local = 1;
	return local;
}

int& ref2() {
	int local = 2;
	return static_cast<int &>(local);
}

int main() {
	cout << endl;
	cout << "ref1() = " << ref1() << endl;
	cout << "ref2() = " << ref2() << endl;
	cout << endl;

	return EXIT_SUCCESS;
}

