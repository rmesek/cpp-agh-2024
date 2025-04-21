#include <iostream>
using namespace std;

class Point {

public:
	explicit Point(double x = 0, double y = 0) : x{x}, y{y} {
		cout << "Point()" << endl;
	}
	~Point() { cout << "~Point()" << endl; }
	void print() const {
		cout << "(" << x << ", " << y << ")" << endl;
	}

//private:
protected:
	double x, y;
};

class NamedPoint : public Point {

public:
	NamedPoint(double x, double y, string name) :
			Point(x, y), name{std::move(name)} {
		cout << "NamedPoint()" << endl;
	}

	NamedPoint(double x, double y) : Point(x, y) {
//	equivalent to
//	NamedPoint (double x, double y) : Point(x, y), name(string()) {
//	so we must have default constructor in string class
		cout << "NamedPoint()" << endl;
	}

	NamedPoint() {
//	equivalent to 
//	NamedPoint () : Point(), name(string()) {
//	so we must have default constructor in Point class and in string class
		cout << "NamedPoint() ..." << endl;
	}
	~NamedPoint () {
		cout << "~NamedPoint() ..." << endl;
	}
	void print () {
		cout << name << ": (" << x << ", " << y << ")" << endl;
//		cout << name << ": ";
//		Point::print1();
	}

private:
	string name;
};

void print(const Point &p) {
	p.print();
}

int main () {
	NamedPoint().print();
	cout << endl;
	NamedPoint(1, 3).print();
	cout << endl;
	NamedPoint(3, 5, "Point"s).print();
	cout << endl;
	print(Point(3, 5));
	cout << endl;
	print(NamedPoint(3, 5, "Point"s));

	return EXIT_SUCCESS;
}

