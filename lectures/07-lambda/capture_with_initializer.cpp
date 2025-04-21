#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<string> vs { "a"s, "b"s, "c"s, "d"s };

	auto it = find_if(vs.begin(), vs.end(), [] (string const& s) {
		return s == "a"s;
	});
	if (it != vs.end()) {
		cout << *it << endl;
	}

	it = find_if(vs.begin(), vs.end(), [p = "a"s] (string const& s) {
		return s == p;
	});
	if (it != vs.end()) {
		cout << *it << endl;
	}
	cout << endl;

	int x = 4;
	auto y = [&r = x, x1 = x + 1] {
		r += 2; // r = 6, x1 = 5
		return x1 * x1; // 5 * 5 = 25
	};
	cout << y() << " " << x << endl; // prints: 25 6

	return EXIT_SUCCESS;
}

