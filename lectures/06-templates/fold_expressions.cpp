#include <iostream>
using namespace std;

// fold expressions: C++17

//	( ... op pack )			unary left fold
//	( pack op ... )			unary right fold
//	( init op ... op pack )	binary left fold
//	( pack op ... op init )	binary right fold

//	The instantiation of a fold expression expands the expression e as follows:

//	Unary left fold (... op E)			becomes (((E1 op E2) op ...) op EN)
//	Unary right fold (E op ...)			becomes (E1 op (... op (E{N-1} op EN)))
//	Binary left fold (I op ... op E)	becomes ((((I op E1) op E2) op ...) op EN)
//	Binary right fold (E op ... op I)	becomes (E1 op (... op (E{N−1} op (EN op I))))

// Binary folds are useful for empty parameter list; unary (usually) don't work

//	op - any of the following 32 binary operators: + - * / % ^ & | = < > << >>
//	+= -= *= /= %= ^= &= |= <<= >>= == != <= >= && ||.
//	In a binary fold, both ops must be the same.

//	pack - an expression that contains an unexpanded parameter pack and does not
//	contain an operator with precedence lower than cast at the top level
//	(formally, a cast-expression)

//	init - an expression that does not contain an unexpanded parameter pack and
//	does not contain an operator with precedence lower than cast at the top
//	level (formally, a cast-expression). Note that the open and closing
//	parentheses are part of the fold expression.


template<typename... Args> auto sum_left(Args... args) {
	// Unary left fold
	return (... + args);
}

template<typename... Args> auto sum_right(Args... args) {
	// Unary right fold
	return (args + ...);
}

template<typename... Args> auto binary_sum_left(Args... args) {
	// Binary left fold
	return (0 + ... + args);
}

template<typename... Args> auto binary_sum_right(Args... args) {
	// Binary left fold
	return (args + ... + 0);
}

template<typename... Args> auto sum_right_sq(Args... args) {
	// Binary left fold - sum of squares
	return (0 + ... + (args*args));
}

template<typename ... Args> void print_binary(Args ... args) {
	// binary left fold over << operator
	(cout << ... << args);
	cout << endl;
}

template<typename ... Args> void print(Args ... args) {
	// unary right fold over comma operator
	((cout << args << " ") , ...);
	cout << endl;
}

template<typename ... Args, typename T> void print_with_sep(const string& sep, T tail, Args ... args) {
	// the template parameter pack must be the final parameter in the template parameter list
	((cout << args << sep) , ...);
	cout << tail << endl;
}

int main() {

	cout << sum_left(1.1, 2.0f, 3) << endl;
	cout << sum_right(1.2, 2.0f, 3) << endl;
	cout << binary_sum_left(1.3, 2.0f, 3) << endl;
	cout << binary_sum_right(1.4, 2.0f, 3) << endl;
//	cout << sum_left() << endl;
//	cout << sum_right() << endl;
	cout << binary_sum_left() << endl;
	cout << binary_sum_right() << endl;
	cout << sum_left("aaa "s, "bbb "s, "ccc"s) << endl;

	cout << sum_right_sq(1.0, 2.0f, 3) << endl;

	print_binary(5.0, 6.0f, 7, "text"s);
	print(5.0, 6.0f, 7, "text"s);
    print_with_sep(" ", "text"s, 5.0, 6.0f, 7);
    print_with_sep(" - ", "text"s, 5.0, 6.0f, 7);

	return EXIT_SUCCESS;
}

