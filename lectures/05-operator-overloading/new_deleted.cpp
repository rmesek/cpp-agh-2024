#include <iostream>
using namespace std;

//	Objects of Test cannot be dynamically allocated
//	operator new() is deleted
class Test {
public:
	Test() { cout << "Test()" << endl; }
	~Test() { cout << "~Test()" << endl; }
	void* operator new(size_t) = delete;
};

int main() {

//	Uncommenting following line would cause compile time error.
//	Test* obj = new Test();
	Test t; // Ok

	return EXIT_SUCCESS;
}

