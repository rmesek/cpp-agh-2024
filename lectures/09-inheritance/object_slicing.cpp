#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Pet {

public:
	explicit Pet(string name) : name{std::move(name)} {}

	virtual ~Pet() = default;

	[[nodiscard]]
	virtual string description() const {
		return "This is pet " + name;
	}

protected:
	string name;
};

class Dog : public Pet {
	string favoriteActivity;
public:
	Dog(const string& name, string activity) : Pet{name}, favoriteActivity{std::move(activity)} {}
	[[nodiscard]]
	string description() const override {
		return "Dog " + name + " likes to " + favoriteActivity;
	}
};

void describe(Pet p) { // Slices the object
	cout << "slicing: " << p.description() << endl;
}

void describe_ref(const Pet &p) { // Pass by reference
	cout << "reference: " << p.description() << endl;
}

int main() {
	Pet p("Alfred");
	Dog d("Fluffy", "sleep");

	describe(p);
	describe(d);
	cout << endl;

	describe_ref(p);
	describe_ref(d);

	return EXIT_SUCCESS;
}

