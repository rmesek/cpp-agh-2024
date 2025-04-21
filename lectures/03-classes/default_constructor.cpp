#include <iostream>
using namespace std;

//	Implicitly-declared default constructor

//	If no user-declared constructors of any kind are provided for a class type
//	(struct, class, or union), the compiler will always declare a default
//	constructor as an inline public member of its class. If some user-declared
//	constructors are present, the user may still force the automatic generation
//	of a default constructor by the compiler that would be implicitly-declared
//	otherwise with the keyword default.

//	Implicitly-defined default constructor

//	If the implicitly-declared default constructor is not defined as deleted, it
//	is defined (that is, a function body is generated and compiled) by the
//	compiler, and it has exactly the same effect as a user-defined constructor
//	with empty body and empty initializer list. That is, it calls the default
//	constructors of the bases and of the non-static members of this class. If
//	some user-defined constructors are present, the user may still force the
//	automatic generation of a default constructor by the compiler that would be
//	implicitly-declared otherwise with the keyword default.

//	Deleted implicitly-declared default constructor

//	The implicitly-declared or defaulted default constructor for class T is
//	undefined (until C++11) defined as deleted (since C++11) if any of the
//	following is true:

//	1) T has a member of reference type without a default initializer.
//	2) T has a const member without user-defined default constructor or
//		a default member initializer.
//	3) T has a member which has a deleted default constructor, or its default
//		constructor is ambiguous or inaccessible from this constructor.
//	4) T has a direct base which has a deleted default constructor.
//	5) T has a direct base which has a deleted destructor, or a destructor
//		that is inaccessible from this constructor. 

//	If no user-defined constructors are present and the implicitly-declared
//	default constructor is not trivial, the user may still inhibit the automatic
//	generation of an implicitly-defined default constructor by the compiler with
//	the keyword delete.

class A {
public:
	explicit A(int x = 1) : x{x} {
		cout << "A()" << endl;
	} // user-defined default constructor
private:
	int x;
};

class B : A { // inheritance
	// B::B() is implicitly-defined, calls A::A()
};

class C { // composition
	A a;
	// C::C() is implicitly-defined, calls A::A()
};

class D : A {
public:
	explicit D(int y) : A(y) {}
	// D::D() is not declared because another constructor exists
};

class E : A {
public:
	explicit E(int y): A(y) {}
	E() = default; // explicitly defaulted, calls A::A()
};

//	A reference must be initialized to refer to something; it can't refer to
//	nothing, so you can't default-construct a class that contains one

class F {
	int& ref; // reference member
	const int c; // const member
public:
	// F(int r, int c) : ref(r), c(c) {} // the only way to initialize consts & refs
	// F::F() is implicitly defined as deleted
};

int main() {
	A a;
	B b;
	C c;
//	D d; // compile error, D::D() not declared
	E e;
//	F f; // compile error, F::F() deleted

	return EXIT_SUCCESS;
}

