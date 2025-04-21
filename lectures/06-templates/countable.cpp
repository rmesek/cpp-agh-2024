#include<iostream>
using namespace std;

//	Curiously recurring template pattern: (James O. Coplien)

//	Example: counter

//	Regular class 'Countable' would count objects of all derived classes
//	together, since static fields are common for all derived classes. But if
//	class Countable is template ...

//	Each time an object of class X is created, the constructor of Countable<X> is
//	called, incrementing the _counter. Each time an object of class X is
//	destroyed, the _counter is decremented. It is important to note that
//	Countable<X> and Countable<Y> are two separate classes and this is why they
//	will keep separate counts of X's and Y's. In this example of CRTP, this
//	distinction of classes is the only use of the template parameter and the
//	reason why we cannot use a simple un-templated base class.

template<typename T>
class Countable {

public:
	Countable() { ++_counter; }
	Countable(const Countable &) { ++_counter; }
	virtual ~Countable() { --_counter; }
	static size_t get_counter() { return _counter; }
	static size_t* get_counter_ptr() { return &_counter; }

private:
	static size_t _counter;
};

template<typename T>
size_t Countable<T>::_counter {};

struct X : public Countable<X> {};
struct Y : public Countable<Y> {};

int main() {

	cout << "&X::_counter: " << X::get_counter_ptr() << endl;
	cout << "&Y::_counter: " << Y::get_counter_ptr() << endl;
	cout << endl;

	X* pX = new X;
	X* pX_array = new X[3];
	Y* pY_array = new Y[5];
	cout << X::get_counter() << endl;
	cout << Y::get_counter() << endl;
	cout << endl;

	delete pX;
	cout << X::get_counter() << endl;
	cout << Y::get_counter() << endl;
	cout << endl;

	delete[] pX_array;
	cout << X::get_counter() << endl;
	cout << Y::get_counter() << endl;
	cout << endl;

	delete[] pY_array;
	cout << X::get_counter() << endl;
	cout << Y::get_counter() << endl;

	return EXIT_SUCCESS;
}

