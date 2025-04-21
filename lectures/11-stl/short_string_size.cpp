#include <iostream>
using namespace std;

// In C++20, we also have a new keyword, constinit -
// it forces constant initialization of non-local objects.
// In short, our object will be initialized at compile time,
// but we can later change it like a regular global variable.
constinit string str15 {"123456789012345"};

void* operator new(std::size_t size) {
	auto ptr = malloc(size);
	if (!ptr)
		throw std::bad_alloc{};
	cout << "new: " << size << ", ptr: " << ptr << endl;
	return ptr;
}

void operator delete(void *p) noexcept {
	cout << "delete: " << "ptr: " << p << endl;
	free(p);
}

void allocate_string(int n) {
	string s1 (n, 'a');
	auto *ptr1 = s1.data();
	cout << s1 << ", " << (void*)ptr1 << endl;
//	cout << endl;
}

int main() {
	const auto empty_capacity = string{}.capacity();
	cout << "empty string capacity: " << empty_capacity << endl;
	cout << endl;

	allocate_string(15);
	cout << endl;

	allocate_string(16);
	cout << endl;

	allocate_string(17);
	cout << endl;

	cout << str15 << endl;
	str15 = "abc";
	cout << str15 << endl;
}

