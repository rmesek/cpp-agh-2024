#include <iostream>
using namespace std;

//	When a class has private destructor, only dynamic objects of that class can
//	be created. Following is a way to create classes with private destructors
//	and have a function as friend of the class. Only this function can delete the
//	objects.

//	A class whose object can only be dynamically created
class DynamicClass {

public:
	DynamicClass() { cout << "DynamicClass()" << endl; }

	friend void delete_object(DynamicClass* ptr) {
		cout << "delete_object()" << endl;
		delete ptr;
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
	delete_object(ptr);

	return EXIT_SUCCESS;
}

