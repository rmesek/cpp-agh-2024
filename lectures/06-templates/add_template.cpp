#include <iostream>
using namespace std;

//	Forward declarations

// The function template has to be declared as a template before
// the class body, in which case the friend declaration within Foo<T>
// can refer to the full specialization of operator<< for its T:

template<class T> class Box;
template<class T> Box<T> operator+(const Box<T>&, const Box<T>&);
template<class T> ostream& operator<<(ostream&, const Box<T>&);

template<class T> class Box {

public:
//	explicit
	Box(const T& t) : t(t) {}
	friend Box operator+ <>(const Box<T>&, const Box<T>&);
	friend ostream& operator<< <>(ostream&, const Box<T>&);

private:
	T t;
};

template<class T>
Box<T> operator+(const Box<T>& box_1, const Box<T>& box_2) {
	return Box<T>(box_1.t + box_2.t);
}

template<class T>
ostream& operator<<(ostream& os, const Box<T>& box) {
	return os << '[' << box.t << ']';
}

int main() {
	cout << Box(1) + Box(2) << endl;    // [3]
//	cout << Box(1) + 2 << endl;         // No implicit conversions!

	return EXIT_SUCCESS;
}

