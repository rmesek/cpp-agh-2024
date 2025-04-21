#include <iostream>
using namespace std;

template<int n> struct factorial {	//	n! = n * (n-1)!
	static_assert(n > 0);
	enum { val = n * factorial<n-1>::val };
};

template<> struct factorial<0> {	//	0! = 1
	enum { val = 1 };
};

template<int n> struct fibonacci {	//	fib_n = fib_{n-1} + fin_{n-2}
	static_assert(n > 1);
	static constexpr int val = fibonacci<n-2>::val + fibonacci<n-1>::val;
};

template<> struct fibonacci<0> {	//	fib_0 = 0
	static constexpr int val = 0;
};

template<> struct fibonacci<1> {	//	fib_1 = 1
	static constexpr int val = 1;
};

// static_assert ( bool-constexpr <, msg> )
// If bool-constexpr is well-formed and evaluates to true,
// this declaration has no effect.
// Otherwise, a compile-time error is issued, and the text of message,
// if any, is included in the diagnostic message.

int main() {
	static_assert(factorial<5>::val == 120);
	static_assert(fibonacci<6>::val == 8);
	cout << factorial<5>::val << endl;
	cout << fibonacci<6>::val << endl;

	return EXIT_SUCCESS;
}

