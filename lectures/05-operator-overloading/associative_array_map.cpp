#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main () {
	map<string, int> word_map;

	string str;
	while(cin >> str) {
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		++word_map[std::move(str)];
	}

	for(const auto &item : word_map) {
		cout << item.first << ": " << item.second << endl;
	}

	return EXIT_SUCCESS;
}

