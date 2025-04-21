#include <iostream>
#include <utility>
using namespace std;

class Point {

public:
	explicit Point(double x = 0, double y = 0, string  name = "") :
		x{x}, y{y}, name{std::move(name)} {}

	friend ostream& operator<< (ostream& o, const Point& p) {
		return o << p.name << ": (" << p.x << ", " << p.y << ")";
	}

	friend istream& operator>> (istream& i, Point& p) {
		return i >> p.name >> p.x >> p.y;
	}

private:
	double x, y;
	string name;
};

int main () {
	Point point1 (1, 4, "Point 1"), point2;
	cout << point1 << endl;

	cout << "Enter name, x, y: ";
	cin >> point2;
	cout << point2 << endl;

	return EXIT_SUCCESS;
}

