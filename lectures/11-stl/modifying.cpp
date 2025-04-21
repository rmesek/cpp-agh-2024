#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include "../includes/random_generator.h"
using namespace std;

void print(const vector<int>& v, const string& s) {
	cout << s << ": ";
	for(int val : v) cout << val << " ";
	cout << endl;
}

int main() {
	vector<int> v(5);
	iota(v.begin(), v.end(), 1);	//	1, 2, 3, 4, 5

	print(v, "original");
	transform(v.begin(), v.end(), v.begin(), [](int n) { return n * n; });
	print(v, "transform");

	swap(v[0], v[3]);
	print(v, "swap");

	v[2] = v[0];
	replace(v.begin(), v.end(), 16, 99);
	print(v, "replace");

	generate(v.begin(), v.end(), [] { return randomize::random_int(0, 99); });
	print(v, "generate");

	return 0;
}

