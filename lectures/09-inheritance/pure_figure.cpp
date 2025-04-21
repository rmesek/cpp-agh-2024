#include <iostream>
using namespace std;

class Figure {

public:
	Figure (double x, double y) : x{x}, y{y} {}
	virtual ~Figure() = default;
	void print_location() const {
		cout << "Location: (" << x << ", " << y << ")" << endl;
	}
	virtual void draw() const {
		cout << "Figure: You must override this function" << endl << endl;
	}
//	virtual void draw() const = 0;

protected:
	double x, y; // location of the figure
};

class Rectangle : public Figure {
public:
	Rectangle(double x, double y, double width, double height) :
		Figure(x, y), width{width}, height{height} {}

	void draw() const override {
		cout << "Rectangle" << endl;
		print_location();
		cout << "Dimensions: " << width << ", " << height << endl;
		cout << endl;
	}

private:
	double width, height;
};

class Circle : public Figure {
public:
	Circle(double x, double y, double radius) :
		Figure(x, y), radius{radius} {}

	void draw() const override {
		cout << "Circle" << endl;
		print_location();
		cout << "Radius: " << radius << endl;
		cout << endl;
	}

private:
	double radius;
};

void draw (const Figure &f) {
	f.draw();
}

int main () {
	draw(Figure(2, 3)); // Error: cannot instantiate abstract class
	draw(Rectangle(5, 3, 4, 6));
	draw(Circle(6, 6, 7));

    return EXIT_SUCCESS;
}

