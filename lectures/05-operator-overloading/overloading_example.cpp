#include <iostream>
#include <format>

using namespace std;

class Vector {

public:
	explicit Vector(double x = 0, double y = 0) : x{x}, y{y} {}
	Vector& operator+=(const Vector& v) {
		x += v.x;
		y += v.y;
		return *this;
	}
	void print(const string& msg) const {
		cout << format("{}: ({}, {})\n", msg, x, y);
	}

private:
	double x, y;
};

//	Useful trick: use previously defined (op)= operator to define (op) operator
//	Here (op) is +

Vector operator+(const Vector& v1, const Vector& v2) {
	Vector v{v1};
	return v += v2;
}

int main () {
	Vector vector1{10, 10}, vector2 {5, 3};
	vector1.print("vector1");
	vector2.print("vector2");

	vector1 += vector2;	// equivalent to: vector1.operator+=(vector2);
	vector1.print("vector1 += vector2");
	Vector vector3 = vector1 + vector2;	// operator+(vector1, vector2);
	vector3.print("vector1 + vector2");
	Vector vector4 = vector1 + vector2 + vector3; // vector4 = ((vector1 + vector2) + vector3);
	vector4.print("vector1 + vector2 + vector3");

	return EXIT_SUCCESS;
}

