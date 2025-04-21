//	It is possible to provide a definition for a pure virtual function in the base
//	class. You are still telling the compiler not to allow objects of that abstract
//	base class, and the pure virtual functions must still be defined in derived
//	classes in order to create objects. However, there may be a common piece of code
//	that you want some or all of the derived class definitions to call rather than
//	duplicating that code in every function.

#include <iostream>
using namespace std;

class Pet {
public:
	virtual ~Pet() = default;
	virtual void speak() const = 0;
	virtual void play() const = 0;
//	Inline pure virtual definitions illegal:
};

//	OK, not defined inline
void Pet::speak() const {
	cout << "Pet::speak()" << endl;
}

void Pet::play() const {
	cout << "Pet::play()" << endl;
}

class Dog : public Pet {
public:
//	Use the common Pet code:
	void speak() const override {
		Pet::speak();
		cout << "Dog barks" << endl;
	}

	void play() const override {
		Pet::play();
		cout << "Dog plays catch" << endl;
	}
};

int main() {

	Dog pluto;
	pluto.speak();
	pluto.play();

	return EXIT_SUCCESS;
}

