#include <iostream>
using namespace std;

//	C++11 proposed a new feature called delegating constructors.

//	You can concentrate common initialization steps in a constructor, known as
//	the target constructor. Other constructors can call the target constructor
//	to do the initialization. These constructors are called delegating
//	constructors.

//	Delegating constructors cannot have initializations of class members in
//	their initializer lists; that is, a constructor cannot delegate and
//	initialize at the same time.

class A {

public:
	A(int num1, int num2) : num1{num1}, num2{num2}, average{(num1 + num2) / 2.} { // target ctor
		cout << "A(int, int)" << endl;
	}

	explicit A(int num1) : A(num1, 0) { // delegating ctor
		cout << "A(int)" << endl;
	}

	A() : A(0) { // delegating ctor
		cout << "A()" << endl;
	}

	void print() const {
		cout << num1 << ", " << num2 << ", " << average << endl;
		cout << "-----------------------------" << endl << endl;
	}

private:
	int num1;
	int num2;
	double average;
};

int main(){

	A{}.print();
	A{1}.print();
	A{2, 3}.print();

	return EXIT_SUCCESS;
}

