#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<typename T>
concept is_iterable = requires(T a) { a.begin(); a.end(); };

template <is_iterable C>
void print(const string &s, const C &c) {
	cout << s;
	for_each(c.begin(), c.end(), [](auto v) { cout << v << " "; } );
	cout << endl;
}

int main() {
	constexpr int element_count = 25;
	vector<int> v(element_count);
	v[0] = 0;
	v[1] = 1;

	// These variables hold the previous two elements of the vector.
	int x = 0;
	int y = 1;

	// Sets each element in the vector to the sum of the
	// previous two elements -> Fibonacci series
	generate(v.begin() + 2, v.end(), [x, y] mutable {
		int next = x + y;
		x = y;
		return y = next;
	});
	print("vector v after call to generate() with lambda: ", v);

	// Print the local variables value and y.
	// value and y hold their initial values because they are captured by value.
	cout << "x: " << x << " y: " << y << endl;

	return EXIT_SUCCESS;
}

