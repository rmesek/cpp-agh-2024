#include <iostream>
#include "../includes/random_generator.h"
using namespace std;

class Matrix {

public:
	explicit Matrix(int n = N) : n{n} {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				m[i][j] = randomize::random_int(0, 99);
			}
		}
	}

	[[nodiscard]]
	int get_n() const {
		return n;
	}

//	int& operator()(int i, int j) {
	int& operator[](int i, int j) { // since C++23
		//	index validation here if needed ...
		return m[i][j];
	}

	int operator[](int i, int j) const { // since C++23
		//	index validation here if needed ...
		return m[i][j];
	}

private:
	static constexpr int N{10};
	int n;
	int m[N][N]{};
};

ostream& operator<<(ostream& o, const Matrix& matrix) {
	for(int i = 0; i < matrix.get_n(); ++i) {
		for(int j = 0; j < matrix.get_n(); ++j) {
			o << matrix[i, j] << "\t";
		}
		o << endl;
	}
	return o;
}

int main() {
	Matrix matrix(5);
	cout << matrix << endl;

	matrix[0, 0] = randomize::random_int(100, 199);
	cout << "Now matrix[0, 0] = " << matrix[0, 0] << endl;
	cout << endl;
	cout << matrix;

	return EXIT_SUCCESS;
}

