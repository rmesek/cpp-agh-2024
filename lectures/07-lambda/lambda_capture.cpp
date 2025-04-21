#include <iostream>
using namespace std;

int main() {

	static int x{};
	//	Only automatic variables need capturing.
	auto f = [] { return ++x; };	//	we don't know the type of lambda
	cout << endl;
	cout << f() << endl;
	cout << f() << endl;
	cout << f() << endl;

	cout << endl;
	int int_var {42};
	auto capture_by_value = [int_var] {
		cout << "This lambda has a copy of int_var when created: " << int_var << endl;
	};
	auto capture_by_reference = [&int_var] {
		cout << "This lambda captures int_var by reference: " << int_var << endl;
	};
	auto lambda_modifying = [&int_var] {
		cout << "This lambda is modifying int_var by adding 5: " << int_var << endl;
		int_var += 5;
	};

	//	The output is the same all three times, and the same as in the first
	//	call of lambda_func above. The fact that int_var is being incremented in
	//	the loop is irrelevant - the lambda is using a stored copy of the value
	//	of int_var when it was created. So a good way to describe the capture
	//	process is that it captures and saves the value that a variable had at
	//	the time the lambda object was created .

	for(int i = 0; i < 3; i++) {
		int_var++;
		capture_by_value();
	}
	cout << endl;

	//	Since the lambda contains a reference to the outer int_var, every time
	//	the function body is executed, the current value of that variable is
	//	looked up and used

	int_var = 42;
	for(int i = 0; i < 3; i++) {
		int_var++;
		capture_by_reference();
	}
	cout << endl;

	int_var = 42;
	for(int i = 0; i < 3; i++) {
		lambda_modifying();
	}

	cout << endl;
	int sum = 0;
	for(int i = 1; i <= 5; i++) {
		[&sum](int k) { sum += k; }(i);
	}
	cout << "Sum = " << sum << endl;

	return EXIT_SUCCESS;
}

