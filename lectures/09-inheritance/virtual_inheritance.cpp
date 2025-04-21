#include <iostream>
using namespace std;

class Point1D {

public:
	explicit Point1D(double x) : x{x} {}
	void show() {
		_show();
	}

protected:
	double x;
	void _show() const {
		cout << "x = " << x << endl;
	}
};

class Point1D_color : virtual public Point1D {

public:
	Point1D_color(double x, string color) : Point1D{x}, color{std::move(color)} {}
	void show() const {
		Point1D::_show();
		_show();
	}

protected:
	string color;
	void _show() const {
		cout << "color: " << color << endl;
	}
};

class Point2D : virtual public Point1D {

public:
	explicit Point2D(double x = 0, double y = 0) : Point1D{x}, y{y} {}
	void show() const {
		Point1D::_show();
		_show();
	}

protected:
	double y;
	void _show() const {
		cout << "y = " << y << endl;
	}
};

class Point2D_color : public Point2D, public Point1D_color {

public:
	Point2D_color(double x, double y, string color) :
		Point1D(x), // allowed only with virtual inheritance
		Point2D(x, y), Point1D_color(x, std::move(color)) {}
	void show() const {
		Point1D::_show();
		Point2D::_show();
		Point1D_color::_show();
		_show();
	}

private:
	void _show() const {}
};

int main() {
	Point2D_color(1, 4, "green").show();

    return EXIT_SUCCESS;
}

