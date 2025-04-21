#include <iostream>
using namespace std;

template <typename T>
void print_array(T *arr, int n) { // any array
	cout << "template A\n";
	for (int i = 0; i < n; i++) cout << arr[i] << " ";
	cout << endl;
}

///*
template <typename T>
void print_array(T **arr, int n) { // array of pointers
	cout << "template B\n";
	for (int i = 0; i < n; i++) cout << *arr[i] << " ";
	cout << endl;
}
//*/

//	If you remove Template B from the program, the compiler then uses Template A
//	for listing the contents of pd, so it lists the addresses instead of the
//	values. Try it and see. In short, the overload resolution process looks for
//	a function that's the best match.

int main() {
	int int_tab[] = { 1, 2, 3, 4, 5 };
	constexpr int size = (int) (sizeof(int_tab) / sizeof(int_tab[0]));
	int *ptr_tab[size];
	for (int i = 0; i < size; ++i) {
		ptr_tab[i] = int_tab + i;
	}

	print_array(int_tab, size);	//	uses template A
	print_array(ptr_tab, size);	//	uses template B (more specialized)

	return EXIT_SUCCESS;
}


