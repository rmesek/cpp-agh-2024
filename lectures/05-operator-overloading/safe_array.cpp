#include <iostream>
#include "../includes/random_generator.h"
using namespace std;

class Array {

public:
	Array() {
		for (int &element : array) {
			element = randomize::random_int(0, 99);
		}
	}

	//	for mutable arrays:
	int& operator[](int i) {
		if (i >= 0 && i < length) {
			return array[i];
		}
		throw out_of_range("(int&) Index value of " + to_string(i) + " out of bounds");
	}

	//	for const objects:
	// In the above example, operator[] is non-const, and we can
	// use it as an l-value to change the state of non-const objects.
	// However, what if our Array object was const? In this case, we would not
	// be able to call the non-const version of operator[] because that would
	// allow us to potentially change the state of a const object.

	// But we can define a non-const and a const version of operator[] separately.
	// The non-const version will be used with non-const objects, and the const
	// version with const-objects.

	int operator[](int i) const {
		if (i >= 0 && i < length) {
			return array[i];
		}
		throw out_of_range("(int) Index value of " + to_string(i) + " out of bounds");
	}

    friend ostream &operator<<(ostream &os, const Array& a) {
        for (int elem : a.array)
            os << elem << " ";
        return os << endl;
    }

private:
	static constexpr int length{3};
	int array[length]{};
};

int main () {

	Array array;
	cout << array;

	cout << "Changing the array" << endl;
	array[0] = randomize::random_int(100, 199);
    cout << array;
	try {
		cout << array[0] << endl;
		cout << array[4] << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}
	cout << endl;

	const Array const_array;
    cout << const_array;
//	const_array[0] = randomize::random_int(100, 199); // error; array is const
	try {
		cout << const_array[0] << endl;
		cout << const_array[5] << endl;
	} catch (out_of_range &e) {
		cout << e.what() << endl;
	}

	return EXIT_SUCCESS;
}

