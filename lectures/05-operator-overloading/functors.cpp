#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// A Functor
class Increment {

public:
	explicit Increment(int value) : value{value} {}

	// ()operator overloading enables calling
	// operator function() on objects of Increment
	int operator()(int to_add) const {
		return value + to_add;
	}

private:
	int value;
};

void print(const vector<int>& v) {
	for (auto value : v) {
		cout << value << "\t";
	}
	cout << endl;
}

int main() {
	vector<int> v(5);
	iota(v.begin(), v.end(), 1);
	print(v);
	transform(v.begin(), v.end(), v.begin(), Increment(10));
	print(v);

	return EXIT_SUCCESS;
}

