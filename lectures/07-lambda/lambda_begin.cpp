#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> array(10);
	//	output initial value of each element
	//	for_each(array.begin(), array.end(), print1); ==>
	for_each(array.begin(), array.end(), [](int v) { cout << v << " "; });
	cout << endl;

	//	assign a value to each element of a vector
	//	for_each(array.begin(), array.end(), assign); ==>
	for_each(array.begin(), array.end(), [](int& v) { static int n{}; v = n++; });

	//	output updated value of each element
	//	for_each(array.begin(), array.end(), print1); ==>
	for_each(array.begin(), array.end(), [](int v) { cout << v << " "; });
	cout << endl;
	cout << endl;

	cout << [](int a, int b) { return a*b; }(4, 5) << endl;	// (1)
	auto f = [](int a, int b) { return a*b; };	// (2)
	cout << f(4, 5) << endl;
	//	The (1) and (2) are equivalent, and produce the results, 20.
	cout << endl;

	//	case #1 - compiler deduces return type
	cout << [](int n) { return n*n; }(5) << endl;
	//	case #2 - explicit return type
	cout << [](int n) ->int { return n*n; }(5) << endl;

	return EXIT_SUCCESS;
}
