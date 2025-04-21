//	Exceptions clean up objects

//	Exception handling guarantees that as you leave a scope,
//	all objects in that	scope whose constructors have been
//	completed will have destructors called.

#include <iostream>
using namespace std;

class Noisy {

public:
	explicit Noisy(const char* name = "array elem") : object_number(cnt++), name(name) {
		cout << "constructing Noisy " << object_number << " name [" << name << "]" << endl;
		if(object_number == 6) {
			cout << "throwing exception()" << endl;
			throw exception();
		}
	}
	~Noisy() {
		cout << "destructing Noisy " << object_number << " [" << name << "]" << endl;
	}

	void* operator new[](size_t sz) {
		cout << "Noisy::new[]" << endl;
		return ::new char[sz];
	}

	void operator delete[](void* p) noexcept {
		::delete[] (char*)p;
		cout << "Noisy::delete[]" << endl;
	}

	void print() {
		cout << "---------- " << object_number << " [" << name << "]" << endl;
	}

private:
	static int cnt;
	int object_number;
	string name;
};


int Noisy::cnt = 0;
struct X {
	int x{};
};

int main() {
	try {
		// If the requested operation (allocate and construct sequence of Noisy objects)
		// throws, everything done to that point related to those two activities is wound back.
		// That includes both the allocation, and any objects that were successfully
		// constructed (and array request of ten objects fulfilling five, then throwing,
		// will fire destructors for the five that constructed successfully, in reverse
		// order of construction, before relinquishing the memory itself and officiating the throw).
		Noisy n1("before array");
		auto* array = new Noisy[10];
		Noisy n2("after array");
	} catch(exception& e) {
		cout << "caught " << e.what() << endl;
//		exit(1);
	}

	return EXIT_SUCCESS;
}

