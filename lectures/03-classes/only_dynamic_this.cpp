#include <iostream>
using namespace std;

//	Ideally delete operator should not be used for this pointer. However, if
//	used, then following points must be considered.

//	1) delete operator works only for objects allocated using operator new.
//	If the object is created using new, then we can do delete this, otherwise
//	behavior is undefined.

//	2) Once delete this is done, any member of the deleted object should not be
//	accessed

class DynamicClass {

public:
	DynamicClass() { cout << "DynamicClass()" << endl; }

	// Only this function can delete_object objects of DynamicClass
	void delete_object() {
		cout << "delete_object()" << endl;
		delete this;
	}

private:
	~DynamicClass() { cout << "~DynamicClass()" << endl; }
};

int main() {
//	Uncommenting following line would cause compiler error 
//	DynamicClass t1;

// create an object
	auto *ptr = new DynamicClass;

//	Uncommenting following line would cause compiler error 
//	delete ptr;

// delete_object the object to avoid memory leak
	ptr->delete_object();

	return EXIT_SUCCESS;
}

