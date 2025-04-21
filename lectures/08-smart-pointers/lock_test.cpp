#include <iostream>
#include <memory>
using namespace std;

class A {
public:
	explicit A(int value) : value{value} {
		cout << "A()" << endl;
	}
	~A() {
		cout << "~A()" << endl;
	}
	friend ostream &operator<<(ostream &os, const A &a) {
		return os << "a = " << a.value << endl;
	}
private:
	int value;
};

int main() {

	auto sp1 = make_shared<A>(20);
	cout << "sp1 count " << sp1.use_count() << endl; // 1

	weak_ptr<A> wp{sp1};
	cout << "sp1 count " << sp1.use_count() << endl; // 1 (weak doesn't increase count)

	auto sp2 = wp.lock();
	// now sp1 & sp2 point to object A
	cout << "sp1 count " << sp1.use_count() << endl; // 2
	cout << "sp2 count " << sp2.use_count() << endl; // 2
	cout << "wp  count " <<  wp.use_count() << endl; // 2

	sp1.reset();
	// only sp2 left ...
	cout << "*sp2: " << *sp2;
	cout << "sp1 count " << sp1.use_count() << endl; // 0
	// sp2 keeps the object alive
	cout << "sp2 count " << sp2.use_count() << endl; // 1

	return EXIT_SUCCESS;
}

