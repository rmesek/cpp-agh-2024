#include <iostream>
#include <valarray>
using namespace std;

// stream operator for valarray
ostream& operator<<(ostream& o, const valarray<int>& v) {
	o << "<";
	for(auto ve : v) o << ve << " ";
	return o << ">" << endl;
}

template <typename T> void output(const T& value) {
	cout << value << endl;
}

template <typename U, typename... T> void output(const U& head, const T&... tail) {
	cout << head << " ";
	output(tail...);
}

template <typename T> T sum(const T& t) { return t; }

template <typename U, typename... T> U sum(const U& head, const T&... tail) {
    return head + sum(tail...);
//	U s = head;
//	s += sum(tail...);
//	return s;
}

int main() {

	output('5');
	output('5', 2);
	output('5', 2, "string");
	output('5', 2, "string", -1);
	output('5', 2, "string", -1, 0.5f);
	output('5', 2, "string", -1, 0.5f, 16.3);
	output('5', 2, "string", -1, 0.5f, 16.3, valarray<int>{1, 2, 3});

	cout << sum(1) << endl;
	cout << sum(1, 2) << endl;
	cout << sum(1, 2, 3) << endl;
	cout << sum(1, 2, 3, 4) << endl;
	cout << sum(1, 2, 3, 4, 5) << endl;
	cout << endl;

	cout << sum(0.1) << endl;
	cout << sum(0.1, 0.2) << endl;
	cout << sum(0.1, 0.2, 3) << endl;
	cout << endl;

	cout << sum(valarray<int>{1, 2, 3});
	cout << sum(valarray<int>{1, 2, 3}, valarray<int>{3, 4, 5}) << endl;

	cout << sum("one"s) << endl;
	cout << sum("one"s, " two"s) << endl;
	cout << sum("one"s, " two"s, " three"s) << endl;

	return EXIT_SUCCESS;
}

