#include <iostream>
using namespace std;

class Point {

public:
	explicit Point(double x = 0, double y = 0, string s = "")
		: x{x}, y{y}, name{std::move(s)} {}
	friend ostream &operator<< (ostream &o, const Point &p);
	friend istream &operator>> (istream &i, Point &p);

private:
	double x, y;
	string name;
};

ostream &operator<< (ostream &o, const Point &p) {
	return o << p.name << ": (" << p.x << ", " << p.y << ")";
}

istream &operator>> (istream &i, Point &p) {
	return i >> p.name >> p.x >> p.y;
}

int main () {
	Point point1 (1, 4, "Point 1"), point2;
	cout << point1 << endl;

	cout << "Enter name x y: ";
	cin >> point2;
	cout << point2 << endl;

	return EXIT_SUCCESS;
}

