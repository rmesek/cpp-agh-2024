#include <iostream>
#include <memory>
using namespace std;

struct X {
	X() { cout << "X()" << endl; }
	~X() { cout << "~X()" << endl; }
};

void some_function(shared_ptr<X> p3) { // pass by copy
	cout << "@3 Ref Count: " << p3.use_count() << endl;
}

int main() {
	auto p1 = make_shared<X>();
//	auto p1 = shared_ptr<X>(new X);
	cout << "@1 Ref Count: " << p1.use_count() << endl;

	{
		auto p2 = p1;
		cout << "@2 Ref Count: " << p2.use_count() << endl;
		some_function(p2);
		cout << "@4 Ref Count: " << p2.use_count() << endl;
	}

	cout << "@5 Ref Count: " << p1.use_count() << endl;
	p1.reset();
	cout << "@6 Ref Count: " << p1.use_count() << endl;

	return EXIT_SUCCESS;
}
