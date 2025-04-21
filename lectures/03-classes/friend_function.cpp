#include <iostream>
using namespace std;

// forward declaration
class ClassB;

class ClassA {
public:
	explicit ClassA(int num) : num(num) {}
	// friend function declaration
	friend int add(ClassA, ClassB);
private:
	int num;
	//  other fields
};

class ClassB {
public:
	explicit ClassB(int num) : num(num) {}
	// friend function declaration
	friend int add(ClassA, ClassB);
private:
	int num;
	//  other fields
};

// access members of both classes
int add(ClassA objectA, ClassB objectB) {
	return (objectA.num + objectB.num);
}

int main() {
	cout << "Sum: " << add(ClassA{12}, ClassB{24}) << endl;

	return EXIT_SUCCESS;
}

