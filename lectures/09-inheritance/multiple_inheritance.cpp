#include <iostream>
using namespace std;

class Point2D {

public:
	explicit Point2D (double x = 0, double y = 0) : x{x}, y{y} {}
	void show() const {
		_show();
	}

protected:
	void _show() const {
		cout << "<" << x << ", " << y << ">" << endl;
	}

private:
	double x, y;
};

class Color {

public:
	explicit Color (string color = "") : color{std::move(color)} {}
	void show() const {
		_show();
	}

protected:
	void _show() const {
		cout << "Color: " << color << endl;
	}

private:
	string color;
};

class Point2DColor : public Point2D, public Color {
public:
	explicit Point2DColor (double x = 0, double y = 0, string c = ""s) :
		Point2D(x, y), Color(std::move(c)) {}

	void show() {
		Point2D::_show();
		Color::_show();
	}
};

int main () {

	Point2DColor(1, 4, "Green").show();

    return EXIT_SUCCESS;
}

