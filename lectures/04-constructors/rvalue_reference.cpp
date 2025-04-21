//	In C++11 there's a new kind of reference, an "rvalue reference", that will
//	let you bind a mutable reference to an rvalue, but not an lvalue. In other
//	words, rvalue references are perfect for detecting if a value is temporary
//	object or not. Rvalue references use the && syntax instead of just &.

//	Rvalue references allow a function to branch at compile time (via overload
//	resolution) on the condition "Am I being called on an lvalue or an rvalue?"

//If you implement
//	void foo(ClassWithConsts&);
//but not
//	void foo(ClassWithConsts&&);
//then foo can be called on l-values, but not on r-values.

//----------------------------------------------------------------------------------

//If you implement
//	void foo(ClassWithConsts const &);
//but not
//	void foo(ClassWithConsts&&);
//then foo can be called on l-values and r-values,
//but it is not possible to make it distinguish between l-values and r-values.

//That is possible only by implementing
//	void foo(ClassWithConsts&&);
//as well.

//----------------------------------------------------------------------------------

//Finally, if you implement
//	void foo(ClassWithConsts&&);
//but neither one of
//	void foo(ClassWithConsts&);
//and
//	void foo(ClassWithConsts const &);
//then, according to the final version of C++11, foo can be called on r-values,
//but trying to call it on an l-value will trigger a compile error.

//	Experiment commenting out some functions and observing the results

#include <iostream>
using namespace std;

void printReference(int& value) {
	cout << "int&  value = " << value << endl;
}

void printReference(const int& value) {
	cout << "const int& value = " << value << endl;
}

void printReference(int&& value) {
	cout << "int&& value = " << value << endl;
}

int getValue() {
	return 99;
}

int& getValueRef() {
	static int temp_ii = 88;
	return temp_ii;
}

int main() {
	int i = 77;

	printReference(i);
	printReference(i+1);
	printReference(std::move(i));
	printReference(88);
	printReference(getValue());
	printReference(getValueRef());

	return EXIT_SUCCESS;
}

