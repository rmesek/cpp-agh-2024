#define FMT_HEADER_ONLY
//#include <fmt/format.h>
#include <fmt/ranges.h> // instead of format.h to print collections
#include <map>
using namespace std;
using namespace fmt;

void print_map(const map<string, int>& data) {
	println("{}", data);
}

int main() {
	map<string, int> data;

	data["Bob"] = 10;
	data["Rick"] = 22;
	data["Michael"] = 15;
	data["Mark"] = 34;
	data["Rick"] = 23;	//	overwrites the 22 as keys are unique

//	Iterate over the map and print1 out all key/value pairs.
    print_map(data);
	println("");

	println("map size: {}", data.size());
//	default constructor is used to create the new element
	println("map[\"John\"] = {}", data["John"]);
	println("map size: {}", data.size());
	print_map(data);
	println("");

	data.erase(data.find("Bob")); // erasing by iterator
	data.erase("John"); // erasing by key
	data.erase(data.find("Rick"), data.end() ); // erasing by range

    print_map(data);

	return EXIT_SUCCESS;
}

