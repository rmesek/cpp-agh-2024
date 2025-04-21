#include <iostream>
#include <cstdlib>
#include "../includes/random_generator.h"
using namespace std;

class Vector {

public:
	Vector() :  x{randomize::random_float(0., 10.)},
				y{randomize::random_float(0., 10.)},
				z{randomize::random_float(0., 10.)} {
		cout << "Vector()" << endl;
	}

	~Vector() {
		cout << "~Vector()" << endl;
	}

	void *operator new(size_t size) {
		cout << "Overloaded new ...\n";
		return malloc (size);
	}

	void operator delete(void *p) noexcept {
		cout << "Overloaded delete ...\n";
		free(p);
	}

	void *operator new[](size_t size) {
		cout << "Overloaded new[] ...\n";
		return malloc (size);
	}

	void operator delete[](void *p) noexcept {
		cout << "Overloaded delete[] ...\n";
		free(p);
	}

	void print() const {
		cout << "<" << x << ", " << y << ", " << z << ">\n";
	}

private:
	double x, y, z;
};

int main () {
	auto *pv{new Vector};
	pv->print();
	delete pv;
	cout << endl;

	auto *pv_array{new Vector[5]};
	for (int i = 0; i < 5; i++) pv_array[i].print();
	delete[] pv_array;

	return EXIT_SUCCESS;
}

