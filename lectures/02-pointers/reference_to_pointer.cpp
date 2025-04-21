#include <iostream>
using namespace std;

//void increment(int* ptr) { ptr++; }
void increment(int*& ptr) { ptr++; }

int main() {
	int array[] = {10, 11, 12, 13, 14, 15 };
	int* ptr = array;

	for (int n = 0; n < sizeof(array) / sizeof(int); n++) {
		cout << "ptr = " << ptr << "\t*ptr = " << *ptr << endl;
		increment(ptr);
	}

	return EXIT_SUCCESS;
}

