#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

void search(vector<int> v, int val) {
	auto it = find(v.begin(), v.end(), val);
	if(it != v.end()) {
		cout << "Found: " << *it << endl;
	} else {
		cout << "Element: " << val << " not found" << endl;
	}
}

int main() {
	vector<int> v(5);
	iota(v.begin(), v.end(), 1);	//	1, 2, 3, 4, 5

	search(v, 3);
	search(v, 8);

	auto it = find_if(v.begin(), v.end(), [](int n) { return n > 3; });
	cout << "The first number > 3 is: " << *it << endl;
	fill(v.begin(), v.begin() + 3, 7);
	cout << "Number of 7's is: " << count(v.begin(), v.end(), 7) << endl;
	cout << "Number of elements < 7 is: " << count_if(v.begin(), v.end(), [](int n) { return n < 7; }) << endl;
	cout << "min elements is: " << *min_element(v.begin(), v.end()) << endl;
	cout << "max elements is: " << *max_element(v.begin(), v.end()) << endl;

	return 0;
}

