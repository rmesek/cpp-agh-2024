//	class definition
//	access method (private, public)
//	access functions
//	this pointer
//	definition of a member function (inside or outside the class definition)
//	constructors, destructors
//	function attributes (const)
//	object as a function parameter (passing by value vs. passing by reference)

#include <iostream>
using namespace std;

class Point {

public:
	Point (const string& name, double x, double y) { // overloaded constructor
		cout << "Point(const string&, double, double)" << endl;
		this->x = x;
		this->y = y;
		this->name = name;
	}

	explicit Point (const string& name) { // overloaded constructor
		cout << "Point(const string&)" << endl;
		this->x = 0;
		this->y = 0;
		this->name = name;
	}

	~Point() {	//	destructor
		cout << "~Point()" << endl;
	}

//	access functions
	[[nodiscard]]
	double get_x() const { return x; }
	double& get_y() { return y; } // can be used as setter

//	definition of a 'const' function (cannot change the object)
	void print() const {
		cout << name << " (" << x << ", " << y << ")" << endl;
	}

//	function declaration
	void move (double, double);

private:
	string name;
	double x, y;
};

//	definition of a member function outside class body (scope operator mandatory)
void Point::move (double x, double y) {
	this->x += x;
	this->y += y;
}

//	print() function must be 'const' otherwise the 'const'
//	qualifier of the reference parameter will be discarded
void print_point(const Point& p) {
	p.print();
}

int main () {
	Point p1("Point 1", 2, 6);
	p1.print();
	cout << endl;

	{
		Point p2("Point 2");
		p2.print();
		cout << "End of block" << endl;
	}

	cout << endl;
	p1.move (3.5, 7.1);
	cout << "After move()" << endl;
	p1.print();
	cout << endl;

//	cout << p1.x << endl;	//	Error! field 'x' is private
	cout << "x = " << p1.get_x() << endl;	//	OK, get_x() is public
	cout << endl;

	cout << "Global print1 function" << endl;
	print_point(p1);
	p1.get_y() = 7.6;
	print_point(p1);

	return EXIT_SUCCESS;
}

