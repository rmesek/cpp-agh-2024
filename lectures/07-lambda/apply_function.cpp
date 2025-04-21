#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Scale {

public:
	explicit Scale(int scale) : _scale(scale) {}

	// Prints the product of each element in a vector object 
	// and the scale value to the console.
	void apply_scale(const vector<int> &v) const {
		for_each(v.begin(), v.end(), [this](int n) {
			cout << n * _scale << " ";
		});
		cout << endl;
	}

private:
	int _scale;
};

int main() {
	vector<int> values { 1, 3, 5, 2 };

	// Create a Scale object that scales elements by 3 and apply
	// it to the vector object. Does not modify the vector.
	Scale(1).apply_scale(values);
	Scale(3).apply_scale(values);
	Scale(5).apply_scale(values);

	return EXIT_SUCCESS;
}

