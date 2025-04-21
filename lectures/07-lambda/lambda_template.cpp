#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
concept printable = requires(ostream &o, T v) { o << v; };

template <class T>
concept arithmetic = is_arithmetic_v<T>;

//	C++-14
//	Lambda function parameters can now be auto to let the compiler deduce the
//	type. This generates a lambda type with a templated operator() so that the
//	same lambda object can be invoked with any suitable type and a type-safe
//	function with the right parameter type will be automatically generated.

template <arithmetic T>
void negate_all(vector<T>& v) {
	for_each(v.begin(), v.end(), [](auto& n) { n = -n; });
}

template <printable T>
constexpr void print_all(vector<T> const &v) {
	for_each(v.begin(), v.end(), [](const auto& n) { cout << n << " "; });
	cout << endl;
}

int main() {
	vector v { 34, -45, 73 };
	print_all(v);
	negate_all(v);
	cout << "After negate_all():" << endl;
	print_all(v);
	cout << endl;

	vector vd { 3.4, -4.5, 7.3 };
	print_all(vd);
	negate_all(vd);
	cout << "After negate_all():" << endl;
	print_all(vd);
	cout << endl;

	auto divide_by_5 = [](arithmetic auto x) { cout << x / 5 << endl; };
	divide_by_5(1);
	divide_by_5(1.);
//	divide_by_5("1");
	cout << endl;

	return EXIT_SUCCESS;
}

