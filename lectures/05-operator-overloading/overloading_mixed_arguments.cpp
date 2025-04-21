#include <iostream>
#include <format>

using namespace std;

class Vector {

public:
	explicit Vector(double x = 0, double y = 0) : x{x}, y{y} {}

	Vector operator+(double d) const {
		return Vector(x + d, y + d);
	}

	void print(const string& name) const {
		cout << format("{}: ({}, {})\n", name, x, y);
	}

private:
	double x, y;
};

int main () {
	Vector vector1{1, 3};
	vector1.print("vector1");
	Vector vector2 = vector1 + 100;	//	equivalent to: vector2 = vector1.operator+(100);
	vector2.print("vector1 + 100");
//	error! must not be a member function
//	vector2 = 100 + vector1; // vector2 = 100.operator+(vector1) ???

	return EXIT_SUCCESS;
}

