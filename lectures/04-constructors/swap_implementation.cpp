#include <iostream>
using namespace std;

class Vector {

public:
	Vector(int length, int val) : length{length}, v_data{new int[length] } {
		for(int i = 0; i < length; ++i) v_data[i] = val;
	}

	Vector(const Vector &vector) : length{vector.length}, v_data{new int[length] } { // copy ctor
		cout << "copy ctor" << endl;
		copy(vector.v_data, vector.v_data + length, v_data); // stl std::copy
	}

	Vector(Vector &&vector) noexcept : length{vector.length}, v_data{vector.v_data} { // move ctor
		cout << "move ctor" << endl;
		//	important! otherwise, double delete would be called
		vector.v_data = nullptr;
		vector.length = 0;
	}

	Vector& operator=(const Vector& v) { // copy assignment
		cout << "copy assignment" << endl;
		if(this == &v) return *this;
		length = v.length;
		delete[] v_data;
		v_data = new int[length];
		copy(v.v_data, v.v_data + length, v_data);
		return *this;
	}

	Vector& operator=(Vector&& v) noexcept { // move assignment
		cout << "move assignment" << endl;
		if(this == &v) return *this;
		length = v.length;
		v.length = 0;
		delete[] v_data;
		v_data = v.v_data;
		v.v_data = nullptr;
		return *this;
	}

	~Vector() { delete[] v_data; }

	void print() const {
		for(int i = 0; i < length; ++i) {
			cout << v_data[i] << " ";
		}
		cout << endl;
	}

private:
	int length;
	int *v_data;
};

void swap_move(Vector &vector1, Vector &vector2) {
	Vector temp{std::move(vector1)};
	vector1 = std::move(vector2);
	vector2 = std::move(temp);
}

void swap_copy(Vector &vector1, Vector &vector2) {
	Vector temp{vector1};
	vector1 = vector2;
	vector2 = temp;
}

void print_both(const Vector &vector1, const Vector &vector2) {
	cout << "vector1: ";
	vector1.print();
	cout << "vector2: ";
	vector2.print();
	cout << endl;
}

int main () {
	Vector vector1 (3, 100); // three ints with a value of 100
	Vector vector2 (5, 200); // five ints with a value of 200

	print_both(vector1, vector2);

	cout << "std::swap() ..." << endl;
	std::swap(vector1, vector2);
	print_both(vector1, vector2);

	cout << "swap_move() ..." << endl;
	swap_move(vector1, vector2);
	print_both(vector1, vector2);

	cout << "swap_copy() ..." << endl;
	swap_copy(vector1, vector2);
	print_both(vector1, vector2);

	return EXIT_SUCCESS;
}

