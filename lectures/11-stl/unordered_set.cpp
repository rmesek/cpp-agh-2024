#include <iostream>
#include <unordered_set>
#include <algorithm>

int main() {
	std::unordered_set<std::string> set_of_strings;

	set_of_strings.insert("First");
	set_of_strings.insert("second");
	set_of_strings.insert("third");
	set_of_strings.insert("second");

	for (const std::string& s : set_of_strings)
		std::cout << s << std::endl;
}

