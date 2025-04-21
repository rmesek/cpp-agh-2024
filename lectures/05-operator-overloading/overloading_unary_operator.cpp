#include <iostream>
using namespace std;

class Number {

public:

	explicit Number(int v = 0) : val{v} {}

	Number &operator++() { // prefix increment
		val++;
		return *this;
	}

	Number operator++(int) { // postfix increment
		const Number temp = *this;
		// It calls the pre-increment to do most of the work.
		// This cuts down on duplicate code, and makes the class easier to modify.
		++(*this);
		return temp;
	}

	void print(const string& name) const {
		cout << name << ": " << val << endl;
	}

private:
	int val;
};

int main () {
	Number number1{10};
	number1.print("number1");
	cout << endl;

	Number number2{++number1};	//	number2 = number1.operator++();
	number1.print("++number1");
	number2.print("number2");
	cout << endl;

	number2 = number1++;	//	number2 = number1.operator++(0);
	number1.print("number1++");
	number2.print("number2");

	return EXIT_SUCCESS;
}

