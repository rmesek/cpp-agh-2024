#include <iostream>
using namespace std;

class Point1D {

public:
	explicit Point1D (double x = 0) : x{x} {}

protected:
	double x;
	void _show() const {
		cout << "x = " << x << endl;
	}
};

class Point1D_color : public Point1D {

public:
	explicit Point1D_color (double x = 0, string c = "") : Point1D{x}, color{move(c)} {}

protected:
	string color;
	void _show() const {
		Point1D::_show();
		cout << "color: " << color << endl;
	}
};

class Point2D : public Point1D {

public:
	explicit Point2D (double x = 0, double y = 0) : Point1D{x}, y{y} {}

protected:
	double y;
	void _show() const {
		Point1D::_show();
		cout << "y = " << y << endl;
	}
};

class Point2D_color : public Point2D, public Point1D_color {
public:
	explicit Point2D_color (double x = 0, double y = 0, string c = "") :
//		Point2D(x, y), Point1D_color(x, c) {}
		Point2D(x, y), Point1D_color(y, std::move(c)) {}
	void show() const {
//		cout << x; // ERROR: x ambiguous
		cout << "Point2D::x = " << Point2D::x << endl;
		cout << "Point1D_color::x = " << Point1D_color::x << endl;
		cout << endl;
		cout << "Point2D::_show()" << endl;
		Point2D::_show();
		cout << endl;
		cout << "Point1D_color::_show()" << endl;
		Point1D_color::_show();
	}
};

int main () {

	Point2D_color(1, 4, "red").show();

	return EXIT_SUCCESS;
}

