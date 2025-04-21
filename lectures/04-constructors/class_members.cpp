#include <iostream>
using namespace std;

class Point {

public:
	explicit Point(double x = 0, double y = 0) : x{x}, y{y} {
		cout << "Point(double, double)" << endl;
	}
	~Point() {
		cout << "~Point()" << endl;
	}
	void print() const {
//		cout << "Point: (" << x << ", " << y << ")";
		printf("Point: (%g, %g)", x, y);
	}

private:
	double x, y;
};

class Circle {

public:
	Circle(double x, double y, double radius) : point{x, y}, radius{radius} {
		cout << "Circle(double, double, double)" << endl;
	}

	explicit Circle(double radius) : radius{radius} {
//	equivalent to:
//	explicit Circle(double radius) : point{}, radius{radius} {
//	error when there is no default constructor
		cout << "Circle(double)" << endl;
	}

	~Circle() {
		cout << "~Circle()\n";
	}

	void print() const {
		point.print();
		cout << " radius: " << radius << endl;
	}

private:
	Point point;
	double radius;
};

int main() {
	Circle{1, 2, 3}.print();
	cout << endl;
	Circle{4}.print();

	return EXIT_SUCCESS;
}

