#include <iostream>
using namespace std;

class NoVirtualFunctions {

public:
	void x() const {}
	[[nodiscard]] int i() const { return 1; }

private:
	int a{};
};

class OneVirtualFunction {

public:
	virtual void x() const {}
	[[nodiscard]] int i() const { return 1; }

private:
	int a{};
};

class TwoVirtualFunctions {

public:
	virtual void x() const {}
	[[nodiscard]] virtual int i() const { return 1; }

private:
	int a{};
};

int main() {
	cout << endl;
	cout << "int: " << sizeof(int) << endl;
	cout << "void* : " << sizeof(void*) << endl;
	cout << "NoVirtualFunctions: " << sizeof(NoVirtualFunctions) << endl;
	cout << "OneVirtualFunction: " << sizeof(OneVirtualFunction) << endl;
	cout << "TwoVirtualFunctions: " << sizeof(TwoVirtualFunctions) << endl;

	return EXIT_SUCCESS;
}

