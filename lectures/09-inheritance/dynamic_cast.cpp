#include <iostream>
using namespace std;

class Pet {
public:
	virtual ~Pet() = default; // virtual destructor for true polymorphism
};

class Dog : public Pet {};
class Cat : public Pet {};

int main() {
	Pet *pet = new Cat;	//	Upcast

//	dynamic_cast is a type safe downcast operation; the return value will be a
//	pointer to the desired type only if the cast is proper and successful,
//	otherwise 0 is returned. For the dynamic_cast to work, the base class has to
//	be polymorphic (have virtual functions) since dynamic_cast uses information
//	from VTABLE

//	Try to cast it to Dog*:
	cout << "downcast to Dog: " << dynamic_cast<Dog*>(pet) << endl;
//	Try to cast it to Cat*:
	cout << "downcast to Cat: " << dynamic_cast<Cat*>(pet) << endl;
	delete pet;

	return EXIT_SUCCESS;
}

