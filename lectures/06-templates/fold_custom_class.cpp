#include <iostream>
using namespace std;

struct Int {
	int value;
	explicit Int(int v = 0) : value(v) {}
	explicit operator int() const { return value; }
};

ostream& operator<<(ostream& o, const Int& i) {
	return o << i.value;
}

Int operator+(Int const &i, Int const &j) {
	cout << "Adding " << i << " " << j << "\n";
	return Int(i.value + j.value); // cast necessary since ctor explicit
}

Int operator*(Int const &i, Int const &j) {
	cout << "Multiplying " << i << " " << j << "\n";
	return Int(i.value * j.value);
}

template<typename... Args>
auto add_ints_left(Args&&... args) {
	cout << "add_ints_left()" << endl;
	return (Int{0} + ... + args);
}

template<typename... Args>
auto add_ints_right(Args&&... args) {
	cout << "add_ints_right()" << endl;
	return (args + ... + Int{0});
}

template<typename... Args>
auto mul_ints(Args&&... args) {
	return (Int{1} * ... * args);
}

int main() {
	cout << add_ints_left(Int{1}, Int{2}, Int{3}) << "\n\n"; // prints 6
	cout << add_ints_right(Int{1}, Int{2}, Int{3}) << "\n\n"; // prints 6
	cout << add_ints_left() << "\n\n"; // prints 0
	cout << mul_ints(Int{1}, Int{2}, Int{4}) << "\n\n"; // prints 8
	cout << mul_ints() << "\n\n"; // prints 1

	return EXIT_SUCCESS;
}

