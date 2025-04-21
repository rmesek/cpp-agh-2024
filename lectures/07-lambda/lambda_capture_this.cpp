#include <iostream>
using namespace std;

class A {
public:
	void print() const {
		[this] { cout << value << endl; }();
	}
	void incr() {
		[this] { value++; }();
	} // no reference needed -> 'this' is a pointer
private:
	int value{5};
};

int main() {
	A a;
	a.print();
	a.incr();
	a.print();

	return EXIT_SUCCESS;
}

