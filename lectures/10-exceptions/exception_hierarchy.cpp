#include <iostream>
#include <climits>
using namespace std;

class Math_exception : public runtime_error {

public:
	explicit Math_exception(const string& what_arg, int operand_1, int operand_2) :
		runtime_error(what_arg), operand_1{operand_1}, operand_2{operand_2} {}
	~Math_exception() override = default;

protected:
	int operand_1, operand_2;
};

class Int_overflow : public Math_exception {
public:
	Int_overflow(const string& what_arg, string math_operator, int operand_1, int operand_2)
		: Math_exception(what_arg, operand_1, operand_2),
		math_operator(std::move(math_operator)) {}
	~Int_overflow() override = default;

	[[nodiscard]]
	const char *what() const noexcept override {
		static char cs[256];
		sprintf(cs, "%s: %d %s %d",
				Math_exception::what(), operand_1, math_operator.c_str(), operand_2);
		return cs;
	}
private:
	string math_operator;
};

class Div_zero : public Math_exception {
public:
	Div_zero(const string& what_arg, int operand_1, int operand_2)
		: Math_exception(what_arg, operand_1, operand_2) {}
	~Div_zero() override = default;

	[[nodiscard]]
	const char *what() const noexcept override {
		static char cs[256];
		sprintf(cs, "%s: %d / %d", Math_exception::what(), operand_1, operand_2);
		return cs;
	}
};

int add(int x, int y) {
	if ((x > 0 && y > 0 && x > INT_MAX - y) ||
		(x < 0 && y < 0 && x < INT_MIN - y))
		throw Int_overflow("Int_overflow", "+", x, y);
	cout << x << " + " << y << " = " << x+y << endl;
	return x + y;
}

int divide(int x, int y) {
	if (y == 0) throw Div_zero("Div_zero", x, y);
	cout << x << " / " << y << " = " << x / y << endl;
	return x / y;
}

int main () {

	try { 
		add (1,2);
		add (INT_MAX, -2);
		add (INT_MAX, 2);
	}
	catch (Math_exception& me) { // pass by reference!
		cout << me.what() << endl;
	}
	cout << endl;

	try { 
		add (INT_MIN, 2);
		add (INT_MIN, -2);
	}
	catch (Math_exception& me) {
		cout << me.what() << endl;
	}
	cout << endl;

	try { 
		divide (4,2);
		divide (4,0);
	}
	catch (Math_exception& me) {
		cout << me.what() << endl;
	}
	return 0;
}

