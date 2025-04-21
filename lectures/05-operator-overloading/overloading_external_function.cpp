#include <iostream>
#include <format>

using namespace std;

class Vector {

public:
//	explicit
	Vector(double x = 0, double y = 0) : x{x}, y{y} {}

	void print(const string& name) const {
		cout << format("{}: ({}, {})\n", name, x, y);
	}

	friend Vector operator+(const Vector& v1, const Vector& v2);

private:
	double x, y;
};

//	Vector + Vector
//	it's enough to define one operator, since we have converting ctor
//	Caution!!!
//	Conversion sets the y coordinate to 0, so addition with double parameter
//	acts as if we had Complex(d, 0). Consequently, only the x coordinate is
//	modified.

Vector operator+(const Vector &v1, const Vector &v2) {
	return Vector{v1.x + v2.x, v1.y + v2.y};
}

int main () {
	Vector vector1(10, 10), vector2 (5, 3);
	vector1.print("vector1");
	vector2.print("vector2");
	Vector vector3 = vector1 + vector2;
	vector3.print("vector1 + vector2");
	vector3 = vector1 + 100.;	//	operator+(vector1, Vector(100.))
	vector3.print("vector1 + 100");
	vector3 = 200. + vector2;	//	operator+(Vector(200.), vector2);
	vector3.print("200 + vector2");

	return EXIT_SUCCESS;
}

