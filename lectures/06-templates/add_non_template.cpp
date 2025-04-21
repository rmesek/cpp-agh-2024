#include <iostream>
using namespace std;

template<class T>
class Box {

public:
	Box(const T& t) : t(t) {}

private:
	T t;

// Defines non-template (inline) operators.

// A common use case for template friends is declaration of a non-member
// operator overload that acts on a class template, e.g.
// operator<<(std::ostream&, const Foo<T>&) for some user-defined Foo<T>.

// Such operator can be defined in the class body, which has the effect
// of generating a separate non-template operator<< for each T and makes
// that non-template operator<< a friend of its Foo<T>:

	friend Box<T> operator+(const Box<T>& box_1, const Box<T>& box_2) {
		return Box<T>(box_1.t + box_2.t);
	}

	friend ostream& operator<<(ostream& os, const Box<T>& box) {
		return os << '[' << box.t << ']';
	}
};

int main() {
	cout << Box(1) + Box(2) << endl;	//	[3]
	cout << Box(1) +  2 << endl;	    //	[3]

	return EXIT_SUCCESS;
}

