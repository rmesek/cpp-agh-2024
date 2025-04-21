#include <iostream>
#include <vector>
#include <algorithm>
#include "../includes/random_generator.h"
using namespace std;

int main() {

	vector<int> v(10);
	generate(v.begin(), v.end(), [] { return randomize::random_int(-99, 99); });
	for_each(v.begin(), v.end(), [] (int e) { cout << e << " "; });
	cout << endl;

	//	Count the number of even numbers in the vector by
	//	using the for_each function and a lambda.
	int evenCount{};
	for_each(v.begin(), v.end(), [&evenCount] (int n) {
		if ((n & 1) == 0) ++evenCount;
	});
	cout << "There are " << evenCount << " even numbers in the vector." << endl;

	evenCount = (int) count_if(v.begin(), v.end(),
		[] (int n) { return (n & 1) == 0; } );
	cout << "There are " << evenCount << " even numbers in the vector." << endl;

	// find the first even number
	auto result = find_if(v.begin(), v.end(),
				  [](int n) { return (n & 1) == 0; });
	if (result != v.end()) {
		cout << "The first even number in the list is " << *result << "." << endl;
	} else {
		cout << "The list contains no even numbers." << endl;
	}

	return EXIT_SUCCESS;
}

