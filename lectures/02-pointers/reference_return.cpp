#include <iostream>
using namespace std;

int& get (int*, int);
void print(int*, int);

int main () {
	int array[] { 0, 1, 2, 3, 4, 5 };
	int n = sizeof array / sizeof array[0];
	print(array, n);
	cout << endl;

	cout << "array[3] = " << get(array, 3) << endl;
	cout << endl;

	get(array, 2) = 10;
	cout << "After get(array, 2) = 10: " << endl;
	print(array, n);
	return EXIT_SUCCESS;
}

void print (int *ia, int dim) {
	cout << "<";
	for (int i = 0; i < dim; i++)
		cout << ia[i] << ((i == dim - 1) ? ">" : ", ");
	cout << endl;
}

int& get (int *ia, int index) {
	return ia[index];
}

