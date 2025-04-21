#include <iostream>
#include "../includes/random_generator.h"
using namespace std;

class Integer {
public:
	Integer() : value{randomize::random_int(0, 100)} {}
	friend ostream &operator<< (ostream &o, const Integer &i) {
		return o << "I: " << i.value;
	}
private:
	int value;
};

class Point {

public:
	Point() : x{randomize::random_int(1, 10)}, y{randomize::random_int(1, 10)} {}

	friend ostream &operator<< (ostream &o, const Point &p) {
		return o << "(" << p.x << ", " << p.y << ")";
	}

private:
	int x, y;
};

template <class T, int n = 16>
class Buffer {

public:
	ostream &print (ostream &os) const {
		for (int i = 0; i < n; i++) {
			os << buf[i] << (i == n - 1 ? "\n" : ", ");
		}
		return os;
	}

private:
	static_assert(n >= 4, "n has to be >= 4");
	T buf[n];
};

template<typename T, int n>
ostream &operator<<(ostream &os, const Buffer<T, n> &buffer) {
	return buffer.print(os);
}

int main () {

	Buffer<Integer> int_buffer;
	cout << int_buffer << endl;

//	Buffer<Point, 2> point_buffer;	//	error: static assert fails
	Buffer<Point, 4> point_buffer;
	cout << point_buffer << endl;

	constexpr int k = 8;
//	int k = 8; // error: k not const
	Buffer <Integer, k> buffer;
	cout << buffer << endl;

	return EXIT_SUCCESS;
}

