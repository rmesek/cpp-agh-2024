#include <iostream>
#include <iomanip>
using namespace std;

//	Implicitly-declared move constructor

//	If no user-defined move constructors are provided for a class type (struct,
//	class, or union), and all the following is true:

//	there are no user-declared copy constructors;
//	there are no user-declared copy assignment operators;
//	there are no user-declared move assignment operators;
//	there are no user-declared destructors;

//	then the compiler will declare a move constructor as a non-explicit inline
//	public member of its class with the signature T::T(T&&).

//	A class can have multiple move constructors, e.g. both T::T(const T&&) and
//	T::T(T&&). If some user-defined move constructors are present, the user may
//	still force the generation of the implicitly declared move constructor with
//	the keyword default.

struct A {
	A() = default;
	A(const A& o) { cout << "move(A) failed!" << endl; }
	A(A&& o) noexcept { cout << "move(A)" << endl; }
};

A f(A a) { return a; }

struct B : A {
	string s {"B::s"};
	int n{};
	// implicit move constructor B::(B&&)
	// calls s's move constructor
	// and makes a bitwise copy of n
};

struct C : A {
	~C() = default; // destructor prevents implicit move constructor C::(C&&)
};

struct D : A {
	D() = default;
	~D() = default;		// destructor would prevent implicit move constructor D::(D&&)
	D(D&&) = default;	// forces a move constructor anyway
};

int main() {

	cout << "Trying to move A\n";
	A a1 = f(A()); // move-constructs from rvalue temporary
	A a2 = std::move(a1); // move-constructs from xvalue
	cout << endl;

	cout << "Trying to move B\n";
	B b1;
	cout << "Before move, b1.s = " << quoted(b1.s) << "\n";
	B b2 = std::move(b1); // calls implicit move constructor
	cout << "After move, b1.s = " << quoted(b1.s) << "\n";
	cout << endl;

	cout << "Trying to move C\n";
	C c1;
	C c2 = std::move(c1); // calls copy constructor
	cout << endl;

	cout << "Trying to move D\n";
	D d1;
	D d2 = std::move(d1);

	return EXIT_SUCCESS;
}

