#define FMT_HEADER_ONLY
//#include <fmt/format.h>
#include <fmt/ranges.h> // instead of format.h to print collections
#include <set>
#include <unordered_set>
using namespace fmt;
using namespace std;

using my_set = set<int>;
//using my_set = unordered_set<int>;

void print_set(const my_set &s, const string& prompt) {
	println("Set {:5}: {}", prompt, s);
}

int main() {
	
	my_set A { 1, 5, 3, 9, 3, 8, 3, 0 };
	my_set B { 4, 7, 2, 8, 0, 0, 4, 0, 2 };
	my_set C;

	print_set(A, "A");
	print_set(B, "B");

	set_union(A.begin(), A.end(), B.begin(), B.end(),
		  inserter(C, C.begin()));
	print_set(C, "A + B");

	C.clear();
	set_intersection(A.begin(), A.end(), B.begin(), B.end(),
		  inserter(C, C.begin()));
	print_set(C, "A * B");

	C.clear();
	set_difference(A.begin(), A.end(), B.begin(), B.end(),
		  inserter(C, C.begin()));
	print_set(C, "A - B");

	return EXIT_SUCCESS;
}
	
