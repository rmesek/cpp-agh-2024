#define FMT_HEADER_ONLY
//#include <fmt/format.h>
#include <fmt/ranges.h> // instead of format.h to print collections
#include <set>
using namespace std;
using namespace fmt;

template<typename T, typename C>
void print_set(const multiset<T, C> &ms, const string &s) {
	println("{}: {}", s, ms);
}

int main() {
	// empty multiset container
	multiset<int, greater<> > set_1;

	// insert elements in random order
	set_1.insert(40);
	set_1.insert(30);
	set_1.insert(60);
	set_1.insert(20);
	set_1.insert(50);

	// 50 will be added again to the multiset unlike set
	set_1.insert(50);
	set_1.insert(10);

	// printing multiset set_1
	print_set(set_1, "set_1"s);

	// assigning the elements from set_1 to set_2
	multiset<int> set_2(set_1.begin(), set_1.end());

	// print1 all elements of the multiset set_2
	print_set(set_2, "set_2"s);

	// remove all elements up to element
	// with value 30 in set_2
	set_2.erase(set_2.begin(), set_2.find(30));
	print_set(set_2, "set_2 after removal"s);

	// remove all elements with value 50 in set_2
	println("{} elements removed", set_2.erase(50));
	print_set(set_2, "set_2.erase(50)"s);

	return EXIT_SUCCESS;
}

