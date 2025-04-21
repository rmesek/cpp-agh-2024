#include <iostream>
using namespace std;

class A {

public:
	A() : id{count++} { cout << "A[" << id << "]" << endl; }
	~A() { cout << "~A[" << id << "]" << endl; }

private:
	static int count;
	int id;
};

int A::count{0};

int main() {
	A* array = new A[5];
//	delete array;
	delete[] array;

	return EXIT_SUCCESS;
}

