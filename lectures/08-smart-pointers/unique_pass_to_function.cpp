#include <iostream>
#include <memory>
using namespace std;

// Pass smart pointers by value to lend their ownership to the function,
// that is when the function wants its own copy of the smart pointer
// in order to operate on it.

// Pass by reference when the function is supposed to modify the ownership
// of existing smart pointers. More specifically:
// pass a non-const reference to std::unique_ptr if the function might modify it,
// e.g. delete it, make it refer to a different object and so on.

// Go with a simpler raw pointer (can be null) or a reference (can't be null)
// when your function just needs to inspect the underlying object or do something
// with it without messing with the smart pointer.

class Resource {

public:
	explicit Resource(string name) : name(std::move(name)) {
		cout << "Resource(): " << this->name << endl;
	}
	~Resource() {
		cout << "~Resource(): " << this->name << endl;
	}
	friend ostream& operator<<(ostream& out, const Resource &resource) {
		return out << "I am a resource: " << resource.name;
	}

private:
	string name;
};

void take_ownership(unique_ptr<Resource> res) { // pass by value
	if(res) cout << *res << endl;
} // the Resource is destroyed here

void modify_ownership(unique_ptr<Resource>& res) { // pass by reference
	// now the underlying pointer in res changed to 'other resource'
	res = make_unique<Resource>("other resource");
}

// The function only uses the resource, so we'll accept a pointer to the
// resource, not a reference to the whole unique_ptr<Resource>
void use_resource(Resource *ptr, const string& name) { //pass raw pointer
	// Check if unique pointer object is empty
	if(!ptr) cout << "Resource " << name << " is empty" << endl;
	else cout << *ptr << endl;
}

int main() {

	{
		auto ptr1{make_unique<Resource>("resource 1")};
		//	take_ownership(ptr); // This doesn't work, need to use move semantics
		take_ownership(std::move(ptr1)); // index_ok: use move semantics
		use_resource(ptr1.get(), "1"); // get() used here to get a pointer to the Resource
	}
	cout << endl;

	{
		auto ptr2{make_unique<Resource>("resource 2")};
		use_resource(ptr2.get(), "2");
	}
	cout << endl;

	{
		auto ptr3{make_unique<Resource>("resource 3")};
		modify_ownership(ptr3);
		use_resource(ptr3.get(), "3");
	}

	return EXIT_SUCCESS;
}

