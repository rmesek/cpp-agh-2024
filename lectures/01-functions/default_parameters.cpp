#include <iostream>
using namespace std;

void show1(int, float = 2.3, long = 4);
//void show1(int = 1, float = 2.3, long = 4);
void show2(int, int = 0);

void show1(int a = 1, float b, long c) {
//void show1(int a, float b, long c) {
	cout << "show1:";
	cout << " a = " << a;
	cout << " b = " << b;
	cout << " c = " << c;
	cout << endl;
}

void show2(int a, int b) {
	cout << "show2:";
	cout << " a = " << a;
	cout << " b = " << b;
	cout << endl;
}

int main() {

	show1();
	show1(5);
	show1(6, 7.8);
	show1(9, 10.11, 12l);
	cout << endl;
	show2(13);
	show2(14, 15);

	return EXIT_SUCCESS;
}

