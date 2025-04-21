#include <iostream>
using namespace std;

//	In C++17 mode, noexcept, noexcept(true), and throw() are all equivalent.
//	When an exception is thrown from a function declared with any of these
//	specifications, std::terminate is invoked as required by the C++17 standard.

//void handler() noexcept {	//	throws nothing; checked at runtime
void handler() {
	throw exception();
}

int main() {
	try {
		handler();
	} catch(exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}

