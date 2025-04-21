#include <cstdlib>
#include <iostream>
using namespace std;

class Vector {

public:
	explicit Vector(double x = 0., double y = 0., double z = 0.) : x{x}, y{y}, z{z} {
		cout << "Constructing Vector ...\n";
	}

	void print() const {
		cout << "<" << x << ", " << y << ", " << z << ">\n";
	}

private:
	double x, y, z;
};

//	Global new 
void *operator new(size_t size) {
	cout << "Overloaded new ...\n";
	return malloc(size);
}

//	Global delete 
void operator delete(void *p) noexcept {
	cout << "Overloaded delete ...\n";
	free(p);
}
	
int main () {

	cout << "Allocating a Vector ...\n";
	auto *pv = new Vector(1., 2., 3.);
	pv->print();
	delete pv;
	cout << endl;

	cout << "Allocating an int ...\n";
	int *pi = new int(8);
	cout << "*pi = " << *pi << endl;
	delete pi;

	return EXIT_SUCCESS;
}

