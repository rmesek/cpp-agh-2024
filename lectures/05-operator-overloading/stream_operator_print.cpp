#include <iostream>
using namespace std;

class Point {

public:

	explicit Point(double x = 0, double y = 0, string name = "") :
		x{x}, y{y}, name{std::move(name)} {}

	ostream& print(ostream& o) const {
		return o << name << ": (" << x << ", " << y << ")";
	}

	istream& read(istream& i) {
		return i >> name >> x >> y;
	}

private:
	double x, y;
	string name;
};

//	does not have to be friend; uses public member function print()
ostream& operator<<(ostream& o, const Point& p) {
	return p.print(o);
}

istream& operator>>(istream& i, Point& p) {
	return p.read(i);
}

int main () {
	Point point1 (1, 4, "Point 1"), point2;
	cout << point1 << endl;

	cout << "Enter name, x, y: ";
	cin >> point2;
	cout << point2 << endl;
	return EXIT_SUCCESS;
}

