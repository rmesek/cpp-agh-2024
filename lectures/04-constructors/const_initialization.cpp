#include <iostream>
using namespace std;

class ClassWithConsts {

public:
	//	The only way to initialize int_reference and const_int
	//	The compiler must make sure the reference is initialized at compile time
	ClassWithConsts(int const_int, int& int_reference) :
		const_int{const_int}, int_reference{int_reference} {}

	void set_ref(int new_value) {
		int_reference = new_value; // changes value not the reference!!!
	}

	void print() const {
		cout << "const = " << const_int << ", ref = " << int_reference << endl;
	}

private:
	const int const_int;
	int& int_reference;
};

int main () {
	int m = 10;
	ClassWithConsts object(5, m);
	object.print();
	object.set_ref(15);
	object.print();
	cout << "m = " << m << endl;
	m = 20;
	object.print();

	return EXIT_SUCCESS;
}

