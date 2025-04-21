#include <iostream>
using namespace std;

class fibonacci_iterator {
	size_t i {0};
	size_t a {0};
	size_t b {1};
	explicit fibonacci_iterator(size_t i_) : i{i_} {}

public:
	fibonacci_iterator() = default;

	size_t operator*() const { return a; }
	fibonacci_iterator& operator++() {
		const size_t old_b {b};
		b += a;
		a = old_b;
		++i;
		return *this;
	}
	bool operator!=(const fibonacci_iterator &o) const { return i != o.i; }
	friend class fib_range;
};

class fib_range {
	size_t end_n;
public:
	explicit fib_range(size_t end_n_) : end_n{end_n_} {}
	[[nodiscard]]
	static fibonacci_iterator begin() { return fibonacci_iterator{}; }
	[[nodiscard]]
	fibonacci_iterator end() const { return fibonacci_iterator{end_n}; }
};

int main() {
	size_t n;
	cin >> n;
	for (size_t i : fib_range(n)) {
		cout << i << " ";
	}
	cout << endl;
	// or
	fib_range fr(n);
	for (auto it = fr.begin(); it != fr.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
}

