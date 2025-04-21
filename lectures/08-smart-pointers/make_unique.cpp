#include <iostream>
#include <iomanip>
#include <memory>
using namespace std;

class Vector {

public:
	explicit Vector(int x = 0, int y = 0, int z = 0) noexcept : x(x), y(y), z(z) { }

	friend ostream& operator<<(ostream& os, const Vector& v) {
		return os << '<' << "x:" << v.x << " y:" << v.y << " z:" << v.z << '>';
	}

private:
	int x, y, z;
};

int main() {

	constexpr int n = 5;
	// Use the default constructor.
	unique_ptr<Vector> v1 = make_unique<Vector>();
	// Use the constructor that matches these arguments
	unique_ptr<Vector> v2 = make_unique<Vector>(0, 1, 2);
	// Create a unique_ptr to an array of 5 elements
	unique_ptr<Vector[]> v3 = make_unique<Vector[]>(n);

	cout << "make_unique<Vector>():        " << *v1 << endl;
	cout << "make_unique<Vector>(0, 1, 2): " << *v2 << endl;
	cout << "make_unique<Vector[]>():      ";
	for (int i = 0; i < n; i++) {
		cout << setw(i ? 31 : 0) << v3[i] << '\n';
	}

    return EXIT_SUCCESS;
}



