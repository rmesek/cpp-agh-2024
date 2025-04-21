#include <iostream>

using namespace std;

void f(int n) { // #1
	cout << "n = " << n << endl;
}

void f(const char *s) { // #2
	cout << ((s != nullptr) ? "s = "s + s : "nullptr") << endl;
}

int main() {

	//	At last, C++ has a keyword that designates a null pointer constant. nullptr
	//	replaces the bug-prone NULL macro and the literal 0 that have been used as
	//	null pointer substitutes for many years. nullptr is strongly-typed:

	//	C++03
	f(0);	//	which f is called?

	//	C++11
	f("Some text");
	f(nullptr);	//	unambiguous, calls #2
	cout << endl;

	//	nullptr is applicable to all pointer categories,
	//	including function pointers and pointers to members:

	void (*pf)() = nullptr;	//	pointer to function
	cout << "pf = " << pf << endl;

	return EXIT_SUCCESS;
}

