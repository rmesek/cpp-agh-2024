#include <iostream>
using namespace std;

class Person {

public:
	Person(string name, int age) : name(std::move(name)), age(age) {
		cout << "Person()" << endl;
	}
	~Person() {
		cout << "~Person()" << endl;
	}
	ostream& print(ostream& os) const {
		return os << "name: " << name << ", age: " << age << endl;
	}

private:
	string name;
	int age;
};

ostream& operator<<(ostream& os, const Person& person) {
	return person.print(os);
}

class SmartPointer {

public:
	explicit
	SmartPointer(Person *ptr) : ptr{ptr} {
		cout << "SmartPointer()" << endl;
	}

	~SmartPointer() {
		cout << "~SmartPointer()" << endl;
		delete ptr;
	}

	Person& operator*() {
		return *ptr;
	}

	// Overloading arrow operator so that members of Person
	// can be accessed like a pointer
	Person* operator->() {
		return ptr;
	}

private:
	Person *ptr; // pointer to person class
};

int main() {
	SmartPointer pointer(new Person("Scott", 25));
	pointer->print(cout);
	cout << *pointer;
	// no delete needed :)

	return EXIT_SUCCESS;
}
