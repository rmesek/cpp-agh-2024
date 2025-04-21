#define FMT_HEADER_ONLY
#include <fmt/ranges.h>
#include <list>
using namespace std;
using namespace fmt;

template<class T>
void print_list(const list<T> &l, int number) {
	println("list {}: {}", number, l);
//	cout << "list " << number << ": ";
//	for_each(l.begin(), l.end(), [](auto e) { cout << e << " "; });
//	cout << endl;
}

int main() {
	list<int> l1 (5, 2);	// list of 5 2's
	list<int> l2 {1, 2, 4, 8, 6};
	print_list(l1, 1);
	print_list(l2, 2);
	l2.insert(l2.begin(), {1, 2, 4, 8, 6});
	print_list(l2, 2);
	list<int> l3(l2);
	l3.insert (l3.end(), { 6, 4, 2, 4, 6, 5 });
	print_list(l3, 3);

	l3.remove(2);	//	remove all elements with value 2
	print_list(l3, 3);

	l3.splice(l3.begin(), l1);	//	concatenate l1 to l3; clear l1
	print_list(l3, 3);
	print_list(l1, 1);

	l3.unique();
	print_list(l3, 3);

	l3.sort();
	l3.unique();
	print_list(l3, 3);

	return 0;
}
	
