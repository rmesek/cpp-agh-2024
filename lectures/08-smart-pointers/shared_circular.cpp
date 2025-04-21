#include <iostream>
#include <memory>
using namespace std;

class Back;
ostream &operator<<(ostream&, const Back&);

class Forth {

public:
	explicit Forth(string name): name(std::move(name)) {
		cout << this->name << " created" << endl;
	}

	~Forth() {
		cout << name << " destroyed" << endl;
	}

	void sendBack(const string& msg) {
		//Acquire strong ref to listener
//		if (auto receiver = cross_ptr.lock()) {
		if (auto receiver = cross_ptr) {
			cout << "sending message '" << msg << "' to " << *receiver;
		} else {
			cout << "no Back receiver" << endl;
		}
	}

	friend bool set_pointers(shared_ptr<Forth> &p1, shared_ptr<Back> &p2);

	friend ostream &operator<<(ostream& os, const Forth& forth) {
		return os << forth.name << endl;
	}

private:
	string name;
//	weak_ptr<Back> cross_ptr;
	shared_ptr<Back> cross_ptr;
};

class Back {

public:
	explicit Back(string name): name(std::move(name)) {
		cout << this->name << " created" << endl;
	}

	~Back() {
		cout << name << " destroyed" << endl;
	}

	void sendForth(const string& msg) {
		//Acquire strong ref to listener
//		if (auto receiver = cross_ptr.lock()) {
		if (auto receiver = cross_ptr) {
			cout << "sending message '" << msg << "' to " << *receiver;
		} else {
			cout << "no Forth receiver" << endl;
		}
	}

	friend bool set_pointers(shared_ptr<Forth> &p1, shared_ptr<Back> &p2);

	friend ostream &operator<<(ostream& os, const Back& back) {
		return os << back.name << endl;
	}

private:
	string name;
//	weak_ptr<Forth> cross_ptr;
	shared_ptr<Forth> cross_ptr;
};


bool set_pointers(shared_ptr<Forth> &p1, shared_ptr<Back> &p2) {
	if (!p1 || !p2) {
		return false;
	}
	p1->cross_ptr = p2;
	p2->cross_ptr = p1;
	cout << p1->name << " and " << p2->name << " point to each other" << endl;
	return true;
}

// At the end of main(), the back shared pointer goes out of scope first.
// When that happens, back checks if there are any other shared pointers
// that co-own "Back". There are (forth's cross_ptr).
// Because of this, it does not deallocate "Forth" (if it did, then forth's cross_ptr
// would end up as a dangling pointer).

// At this point, we now have one shared pointer to "Back" (forth cross_ptr) and
// two shared pointers to "Forth" (forth, and back's cross_ptr).

// Next the forth shared pointer goes out of scope, and the same thing happens.
// The shared pointer forth checks if there are any other shared pointers co-owning
// "Forth". There are (back's cross_pointer), so "Forth" is not deallocated.

// At this point, there is one shared pointer to "Forth" (back's cross_pointer)
// and one shared pointer to "Back" (forth's cross_pointer).

// Then the program ends -- and neither "Forth" nor "Back" have been deallocated!
// Essentially, "Forth" ends up keeping "Back" from being destroyed, and "Back"
// ends up keeping "Forth" from being destroyed.

// A weak_ptr is an observer -- it can observe and access the same object as a
// shared_ptr, but it is not considered an owner.
// When a shared pointer goes out of scope, it only considers whether other
// shared_ptr are co-owning the object. weak_ptr does not count!

int main() {
	auto forth { make_shared<Forth>("Forth") };
	auto back  { make_shared<Back>("Back") };
	set_pointers(forth, back); // Make forth point to back and vice-versa
	forth->sendBack("A message to Back");
	back->sendForth("A message to Forth");

	return EXIT_SUCCESS;
}

