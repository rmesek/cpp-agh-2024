//	Use of set_terminate()

//	If no handler at any level catches the exception, it is uncaught or
//	unhandled. An uncaught exception also occurs if a new exception is thrown
//	before an existing exception reaches its handler.

//	If an exception is uncaught, function terminate() is automatically called.
//	You can install your own terminate() function using the standard
//	set_terminate() function.
//	terminate() must take no arguments and have a void return value.
//	Any terminate() handler must not return or throw an exception,
//	but instead must call program-termination function.

#include <iostream>
using namespace std;

void terminator() noexcept {
	cout << "terminator()" << endl;
	exit(1);
}

class A {
public:
	A() = default;

	// destructors have default 'noexcept' attribute.
	// noexcept(false) let it throw.
	~A() noexcept(false) {
		cout << "~A()" << endl;
		throw logic_error("In dtor"s);	//	Design error
	}

	static void f() {
		cout << "A::f()" << endl;
		throw exception();
	}
};

int main() {
	set_terminate(terminator);
	try {
		A a;
		A::f();	//	before jumping to 'catch', destructor for 'a' is called
	} catch(exception& e) {
		cout << e.what() << endl;
	}
	return 0;
}

