#include <iostream>
using namespace std;

void display_chars(char, char);

int main () {
	display_chars('a', 'x');
	display_chars('g', 'p');

	return EXIT_SUCCESS;
}

void display_chars (char c1, char c2) {
	for (char c = c1; c < c2; ++c) {
		cout << c;
	}
	cout << endl;
}

