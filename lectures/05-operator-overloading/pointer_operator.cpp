//	It is defined to give a class type a "pointer-like" behavior. The operator
//	-> must be a member function. If used, its return type must be a pointer or
//	an object of a class to which you can apply.

//	The operator-> is used often in conjunction with the pointer-dereference
//	operator* to implement "smart pointers". These pointers are objects that
//	behave like normal pointers except they perform other tasks when you access
//	an object through them, such as automatic object deletion either when the
//	pointer is destroyed, or the pointer is used to point to another object.

//	The dereferencing operator -> can be defined as a unary postfix operator.
//	That is, given a class

//	class Ptr {
//		...
//		X* operator->();
//	};

//  class X {
//      ...
//      int scale;
//  };

//	Objects of class Ptr can be used to access members of class X in a very
//	similar manner to the way pointers are used.

//	Ptr p;
//	p->scale = 10 ; // (p.operator->())->scale = 10

//	the first -> operator is overloaded
//	the second -> operator is built-in

#include <iostream>
using namespace std;

class Number {

public:
	explicit Number(int n) : n{n} {}
	Number *operator->() { return this; }
	void print() const { cout << "n = " << n << endl; }

private:
	int n;
};

int main () {
	Number number{6};

//	with -> operator defined as returning 'this'
//	these are equivalent
	number.print();
	number->print();
//	equivalent to: (number.operator->())->print()
//	equivalent to: (&number)->print()
//	equivalent to: number.print()

	return EXIT_SUCCESS;
}

