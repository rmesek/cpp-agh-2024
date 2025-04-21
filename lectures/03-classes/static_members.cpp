#include <iostream>
using namespace std;

class Point {

public:
	Point (int x, int y) {
		this->x = x;
		this->y = y;
		count++;
	}

	~Point () {
		count--;
		cout << "~Point()" << endl;
	}

	void print() const {
		cout << '<' << x << ',' << y << ">: " << count << endl; 
	}

	static void printCounter() { 
		cout << "Counter = " << count << endl; 
	}

private:
	int x, y;
	static int count;
};

int Point::count{}; // static field definition (obligatory)

void point_test() {

	Point p1(1,3);
	p1.print();
	Point p2(2,4);
	p2.print();
	Point p3(3,5);
	p3.print();
	auto *pp4 = new Point(4,6);
	pp4->print();
	delete pp4;
	cout << "After delete ..." << endl;
	Point::printCounter();
}

int main() {
	Point::printCounter(); // no Point object yet !!!
	point_test();
	Point::printCounter();

	return EXIT_SUCCESS;
}

