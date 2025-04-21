#define FMT_HEADER_ONLY
//#include <fmt/format.h>
#include <fmt/ranges.h> // instead of format.h to print collections
#include <map>
using namespace std;
using namespace fmt;

void print_map(const multimap<int, int> &map_1, const string& header) {
	println("{}:\n{}", header, map_1);
//	cout << header << endl;
//	cout << "\tKEY\tVALUE" << endl;
//	for (const auto &item : map_1) {
//		cout << '\t' << item.first << '\t' << item.second << endl;
//	}
//	cout << endl;
}

int main() {
	multimap<int, int> map_1; // empty multimap container

	// insert elements in random order
	map_1.insert(pair<int, int>(1, 40));
	map_1.insert(pair<int, int>(6, 50));
	map_1.insert(pair<int, int>(2, 30));
	map_1.insert(pair<int, int>(3, 60));
	map_1.insert(pair<int, int>(6, 10));

	// printing multimap map_1
	print_map(map_1, "The multimap map_1"s);

	// adding elements randomly,
	// to check the sorted keys property
	map_1.insert(pair<int, int>(4, 50));
	map_1.insert(pair<int, int>(5, 10));

	// printing multimap map_1 again
	print_map(map_1, "The multimap map_1 after adding extra elements"s);

	// assigning the elements from map_1 to map_2
	multimap<int, int> map_2(map_1.begin(), map_1.end());

	// print all elements of the multimap map_2
	print_map(map_2, "The multimap map_2 after assign from map_1"s);

	// remove all elements up to key with value 3 in map_2
	map_2.erase(map_2.begin(), map_2.find(3));
	print_map(map_2, "The multimap map_2 after removal of elements less than 3"s);

	// remove all elements with key = 6
	auto num = map_2.erase(6);
	print_map(map_2, "map_2.erase(6), "s + to_string(num) + " elements removed"s);

	return EXIT_SUCCESS;
}

