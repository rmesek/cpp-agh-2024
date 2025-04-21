#include <iostream>
using namespace std;

//	This implementation is known as Meyers' Singleton.
//	Scott Meyers says:

//	This approach is founded on C++'s guarantee that local static objects are
//	initialized when the object's definition is first encountered during a call
//	to that function. As a bonus, if you never call a function emulating a
//	non-local static object, you never incur the cost of constructing and
//	destructing the object.

class Singleton {

public:
	Singleton(const Singleton&) = delete; // prohibit copying
	Singleton& operator=(const Singleton&) = delete;
	static Singleton& getInstance() {
		//	thread-safe; static will be created exactly once
		static Singleton instance;
		return instance;
	}

	void set(int f) { field = f; }

	void print() const {
		cout << this << ": field = " << field << endl;
	}

private:
	int field{}; // value-initialized
//	Singleton() = default;
	Singleton() { cout << "Singleton()" << endl; }
//	~Singleton() = default;
	~Singleton() { cout << "~Singleton()" << endl; }
};

int main () {
//	Singleton singleton;							//	Error! default ctor private
//	Singleton singleton{Singleton::getInstance()};	//	Error! copy ctor deleted

	cout << "main()" << endl;
	Singleton& singleton{Singleton::getInstance()};
	singleton.print();
	singleton.set(10);
	singleton.print();

	cout << "main() ended" << endl;

	return EXIT_SUCCESS;
}

