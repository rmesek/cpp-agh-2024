#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	map<string, int> counter;

	string word;
	while(cin >> word) {
		transform(word.begin(), word.end(), word.begin(), ::tolower);
		counter[word]++;
	}

//	Iterate over the map and print1 out all key/value pairs.
	for(const auto& i : counter) {
		cout << i.first << ": " << i.second << endl;
	}

	return EXIT_SUCCESS;
}

