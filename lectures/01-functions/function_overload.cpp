#include <iostream>
using namespace std;

void print(double);
void print(long);

int main() {
	print (1L);
	print (1.0);
	print (1.0f);
//	print (1); // ambiguous
	return EXIT_SUCCESS;
}

void print(double x) {
	cout << "Double: " << x << endl;
}

void print(long x) {
	cout << "Long  : " << x << endl;
}

