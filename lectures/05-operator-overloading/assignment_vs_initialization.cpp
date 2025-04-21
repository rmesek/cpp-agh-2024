#include <iostream>
using namespace std;

class X {

public:
	X() { cout << "X dummy constructor\n"; }
	X(int n) : n{n} { cout << "X int constructor\n"; }
	X(const X &x) : n{x.n} { cout << "X copy constructor\n"; }
	X& operator=(const X &x) { 
		cout << "X assignment operator\n";
		n = x.n; 
		return *this;
	}
	[[nodiscard]]
	int get_n() const { return n; }

private:
	int n{};
};

class Y {

public:
	Y() { x = 5; cout << "Y dummy constructor" << endl; }
	void show () { cout << "y.x.n = " << x.get_n() << endl; }

private:
	X x;
};

class Z {

public:
	Z() : x{7} { cout << "Z dummy constructor" << endl; }
	void show () { cout << "z.x.n = " << x.get_n() << endl; }

private:
	X x;
};

//	Check how many operations is preformed for Y (assignment) vs. Z
//	(initialization). Try to explain why.
int main() {

	Y().show();
	cout << "-------------" << endl;
	Z().show();

	return EXIT_SUCCESS;
}

