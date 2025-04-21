#include <iostream>
#include <cmath>
using namespace std;

// C++ 20

// 1. A defaulted <=> overload will allow the type to be compared with <, <=, >, and >=.
// 2. If operator <=> is defaulted and operator== is not declared at all, then operator==
//		is implicitly defaulted.
// 3. When operator<=> is defined explicitly,
//		an explicit operator== must be defined to get the correct behavior.

struct MyInt {
	int value;

	explicit constexpr MyInt(int val) : value{val} {}

	// supports strong ordering
	// all 6 comparison operators defined
	auto operator<=>(const MyInt&) const = default;
};

ostream &operator<<(ostream &os, const MyInt &v) {
	return os << v.value;
}

struct MyDoubleDefault {
	double value;

	explicit constexpr MyDoubleDefault(double val) : value{val} {}

	// supports partial ordering (Nan, etc.)
	// all 6 comparison operators defined
	auto operator<=>(const MyDoubleDefault&) const = default;
};

ostream &operator<<(ostream &os, const MyDoubleDefault &v) {
	return os << v.value;
}

struct MyDouble {
	constexpr static double eps = 1e-10;
	double value;

	explicit constexpr MyDouble(double val) : value{val} {}

	// supports partial ordering (Nan, etc.)
	auto operator<=>(const MyDouble& rhs) const {
		if (fabs(value - rhs.value) < eps) return partial_ordering::equivalent;
		return value <=> rhs.value;
	}

	// Necessary, since operator<=> is not defaulted
	bool operator==(const MyDouble& rhs) const {
		return fabs(value - rhs.value) < eps;
	}
};

ostream &operator<<(ostream &os, const MyDouble &v) {
	return os << v.value;
}

template <typename T>
void print_relations (T a, T b) {
	cout << boolalpha;
	cout << "a = " << a << " b = " << b << endl;
	cout << "a <  b: " << (a <  b) << endl;
	cout << "a <= b: " << (a <= b) << endl;
	cout << "a >  b: " << (a >  b) << endl;
	cout << "a >= b: " << (a >= b) << endl;
	cout << "a == b: " << (a == b) << endl;
	cout << "a != b: " << (a != b) << endl;
	cout << endl;
}

int main() {
	print_relations(MyInt{1}, MyInt{1});
	print_relations(MyInt{1}, MyInt{2});
	print_relations(MyDoubleDefault{1.}, MyDoubleDefault{2.});
	print_relations(MyDouble{1.}, MyDouble{2.});
	print_relations(MyDoubleDefault{0.}, MyDoubleDefault{1e-15});
	print_relations(MyDouble{0.}, MyDouble{1e-15});

	return EXIT_SUCCESS;
}

