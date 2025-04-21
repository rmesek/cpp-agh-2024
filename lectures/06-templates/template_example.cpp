#include <iostream>
using namespace std;

template<typename T>
void swap_temp (T &a, T &b) {
	T temp = a;
	a = b;
	b = temp;
}

template <class T>
T max_val(const T& a, const T& b) {
	return (a > b) ? a : b;
}

template<typename T>
void print(const string& s, T v1, T v2) {
	cout << s << ": " << v1 << ' ' << v2 << endl;
}

class Point {

public:
	explicit Point(double x = 0, double y = 0) : x{x}, y{y} {}

	friend ostream &operator<< (ostream &o, Point &p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}

private:
	double x{}, y{};
};

int main () {

	int i = 1, j = 2;
	float x = 10.1, y = 23.3;
	Point p(1,2), q(3,4);

	print("Original i j", i, j);
	print("Original x y", x, y);
	print("Original p q", p, q);
	cout << endl;

	swap_temp (i,j);
	swap_temp (x,y);
//	swap_temp (i, y); // ERROR: no function for swap_temp(int, float)
	swap_temp (p,q);

	print("Swapped i j", i, j);
	print("Swapped x y", x, y);
	print("Swapped p q", p, q);
	cout << endl;

	cout << max_val(i, j) << endl;
//	cout << max_val(i, y) << endl; // ambiguous
	cout << max_val<float>(i, y) << endl;

	return EXIT_SUCCESS;
}

