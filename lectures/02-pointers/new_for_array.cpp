#include <iostream>
#include "../includes/random_generator.h"
using namespace std;

void print(int*, int);

int main() {
	int *int_ptr, size;
	cout << "Enter size: ";
	cin >> size;
	int_ptr = new int[size];
	for (int i = 0; i < size; i++) {
		int_ptr[i] = randomize::random_int(0, 99);
	}
	print(int_ptr, size);
	delete[] int_ptr;

	return EXIT_SUCCESS;
}

void print(int *pa, int size) {
	for (int i = 0; i < size; i++) {
		cout << pa[i] << (i == size - 1 ? "\n" : ", ");
	}
}

