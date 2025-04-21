#include <iostream>
using namespace std;

class Point {

public:
	Point (double x, double y) : x{x}, y{y} {}

	void print(const char* name) const {
		cout << name << ": <" << x << ", " << y << ">, " << this << endl;
	}

private:
	double x, y;
};

int main () {
	Point p1 {1, 4};
	Point p2 {p1};

	p1.print("point 1");
	p2.print("point 2");
	return EXIT_SUCCESS;
}

