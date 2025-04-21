#include <iostream>
#include <cstring>
using namespace std;

// Initialization and assigning Derived objects

//	Methods NOT inherited:
//		- constructors,
//		- destructor,
//		- assignment operators

class Base {

public:
	explicit Base(int n) : n{n}, ptr{new int[n]} {
		for(int i = 0; i < n; ++i) ptr[i] = i + 1;
	}

	Base(const Base& base) : n{base.n}, ptr{new int[n]} {
		memcpy(ptr, base.ptr, n * sizeof(int));
		cout << "Base copy ctor ..." << endl;
	}

	Base(Base&& base) noexcept : n{base.n}, ptr{base.ptr} {
		base.n = 0;
		base.ptr = nullptr;
		cout << "Base move ctor ..." << endl;
	}

	Base &operator=(const Base &base) {
		if(&base == this) return *this;
		delete[] ptr;
		n = base.n;
		ptr = new int[n];
		memcpy(ptr, base.ptr, n * sizeof(int));
		cout << "Base copy assignment operator ..." << endl;
		return *this;
	}

	Base &operator = (Base &&base) noexcept {
		if(&base == this) return *this;
		delete[] ptr;
		n = base.n;
		ptr = base.ptr;
		base.n = 0;
		base.ptr = nullptr;
		cout << "Base move assignment operator ..." << endl;
		return *this;
	}

	~Base() { delete[] ptr; }

protected:
	int n, *ptr;
};

// Default copy constructor (if we do not provide one) will invoke
// the copy constructor of each base class (in order), and then the
// copy constructor of each member variable (in order).
// The same is true for assignment operator.

class Derived : public Base {

public:
	explicit Derived(int n = 0, int d = 0) : Base{n}, d{d} {}

///*
	Derived(const Derived &derived) : Base(derived), d{derived.d} {
		cout << "Derived copy ctor ... " << endl;
	}

	Derived(Derived &&derived) noexcept : Base(move(derived)), d{derived.d} {
		cout << "Derived move ctor ... " << endl;
	}

	Derived &operator=(const Derived &derived) {
		if(&derived == this) return *this;
//		*(static_cast<Base *>(this)) = derived;	//	Base part assignment
		Base::operator=(derived);
		d = derived.d;	//	fields of Derived class
		cout << "Derived copy assignment operator ..." << endl;
		return *this;
	}

	Derived &operator=(Derived &&derived) noexcept {
		if(&derived == this) return *this;
//		*(static_cast<Base *>(this)) = derived;	//	Base part assignment
		d = derived.d;	//	fields of Derived class
		Base::operator=(move(derived));
		cout << "Derived move assignment operator ..." << endl;
		return *this;
	}
//*/

	~Derived() = default; // blocks default move constructor & move assignment

	void show() {
		for(int i = 0; i < n; ++i) cout << ptr[i] << " ";
		cout << ": " << d << endl;
	}

private:
	int d;
};

int main() {

	cout << "Initialization ... " << endl;
	Derived derived1(5, 20), derived2{derived1};
	derived1.show();
	derived2.show();
	Derived derived3{std::move(derived1)};
	derived3.show();
	cout << endl;

	cout << "Assignment ... " << endl;
	derived3 = derived2;
	derived3.show();
	derived3 = std::move(derived2);
	derived3.show();

	return EXIT_SUCCESS;
}

