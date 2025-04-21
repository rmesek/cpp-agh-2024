#include <iostream>
#include "../includes/random_generator.h"
using namespace std;

class Integer {

public:
	Integer() : n{randomize::random_int(0, 99)} {}
	friend ostream& operator<< (ostream& out, const Integer& num) {
		return out << "I = " << num.n;
	}

private:
	int n;
};

template <class T>
class Stack {

public:
	bool empty() { return top == 0; }
	bool full() { return top == SIZE; }
	void push(T element) {
		if (full()) error("full");
		stack_array[top++] = element;
	}
	T pop() {
		if (empty()) error("empty");
		return stack_array[--top];
	}

private:
	static constexpr int SIZE{10};
	T stack_array[SIZE]{};
	int top{};

	void error(const string &s) const {
		throw out_of_range("Stack is "s + s);
	}
};

template<class T>
ostream& operator<<(ostream& o, Stack<T>& s) {
	while (!s.empty()) o << s.pop() << " ";
	return o << endl;
}

int main() {
	Stack<char> char_stack;
	while(!char_stack.full()) {
        char_stack.push(randomize::random_int('a', 'z'));
    }
	cout << "char_stack: " << char_stack << endl;

	Stack <double> double_stack;
	while(!double_stack.full()) {
        double_stack.push(randomize::random_float(1., 10.));
    }
	cout << "double_stack: " << double_stack << endl;

	Stack<Integer> integer_stack;
	while(!integer_stack.full()) {
        integer_stack.push(Integer());
    }
	try {
		integer_stack.push(Integer());
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << "integer_stack: " << integer_stack;
	try {
		integer_stack.pop();
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}

