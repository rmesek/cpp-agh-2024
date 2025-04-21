#include <iostream>
using namespace std;

void print (const int*, int);
void change (int*, int);
void const_ptr();

int main() {
	int array[]{1, 2, 3, 4, 5};
	constexpr int n = sizeof array / sizeof array[0];
	print (array, n);
	change (array, n);
	print (array, n);
	const_ptr();

	return EXIT_SUCCESS;
}

void print (const int *array, int n) {
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl << endl;
//	array[2] = 20;	//	error: constant array
}

void change (int *array, int n) {
	for (int i = 0; i < n; i++)
		array[i] += 100;
}

void const_ptr() {
	const int n[] {1, 2};
	const int* cv = &n[0]; // pointer to const
	cout << cv << " " << *cv << endl;
	++cv; // ok
	cout << cv << " " << *cv << endl;
//	*cv = 10; // error - cv points to const
	cout << endl;

	int m[] {5, 6};
	int* const cp = &m[0]; // const pointer
	cout << cp << " " << *cp << endl;
	*cp = 10;
	cout << cp << " " << *cp << endl;
//	++cp; // error - cp is const
	cout << endl;

	const int* const cpv = &n[0];
	cout << cpv << " " << *cpv << endl;
//	*cpv = 20; // error
//	++cpv; //error
	cout << endl;
}

