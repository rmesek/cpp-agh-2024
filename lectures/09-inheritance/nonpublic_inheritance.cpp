#include <iostream>
using namespace std;

class Point1D {

public:
	void set_x (int n = 0) { x = n; }
	[[nodiscard]]
	int get_x() const { return x; }

protected:
	int x{};
};

//	Private inheritance makes all public / protected members
//	of the parent class private in the child class.
//	This means that they can be used in order to implement
//	the child class without being accessible to the outside world. 

//class Point2D : protected Point1D {
class Point2D : private Point1D {

public:
	void set (int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	[[nodiscard]]
	int get_y() const { return y; }

private:
	int y{};
};

int main () {
	Point1D p1;
	p1.set_x(5);
	cout << "x = " << p1.get_x() << endl;

	Point2D p2;
//	p2.set_x(4); // ERROR : set_x() private to derived class
	p2.set(1, 3);
//	cout << "x = " << p2.get_x() << endl; // ERROR : get_x() private to derived class
	cout << "y = " << p2.get_y() << endl;

	return EXIT_SUCCESS;
}

