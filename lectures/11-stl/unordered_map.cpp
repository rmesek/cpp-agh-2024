#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

int main() {
// Create an unordered_map of three strings
	std::unordered_map<std::string, std::string> u = {
//	std::map<std::string, std::string> u = {
		{"RED","#FF0000"},
		{"GREEN","#00FF00"},
		{"BLUE","#0000FF"}
	};

	// Helper lambda function to print1 key:value pairs
	auto print_key_value = [](const auto& key, const auto& value) {
		std::cout << "Key:[" << key << "] Value:[" << value << "]\n";
	};

	std::cout << "Iterate and print1 keys and values of unordered_map\n";
	for (const auto& item : u) {
		print_key_value(item.first, item.second);
	}
	std::cout << "\n";

	// Add two new entries to the unordered_map
	u["BLACK"] = "#000000";
	u["WHITE"] = "#FFFFFF";

	std::cout << "Output values by key:\n";
	std::cout << "The HEX of color RED is:[" << u["RED"] << "]\n";
	std::cout << "The HEX of color BLACK is:[" << u["BLACK"] << "]\n\n";

	// Use of operator[] with non-existent key inserts a new value
	print_key_value("new_key", u["new_key"]);
	std::cout << "Iterating over the unordered_map shows `new_key`\n";
	for( const auto& n : u ) {
		print_key_value(n.first, n.second);
	}
}

