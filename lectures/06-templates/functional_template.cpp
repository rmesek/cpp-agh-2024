#include <iostream>
using namespace std;

struct Cmp {
	static bool eq (unsigned char a, unsigned char b) { return a == b; }
	static bool lt (unsigned char a, unsigned char b) { return a < b; }
};

struct Cmp_insensitive {
	static bool eq (unsigned char a, unsigned char b) { return tolower(a) == tolower(b); }
	static bool lt (unsigned char a, unsigned char b) { return tolower(a) < tolower(b); }
};

template<class C = Cmp>
int cmp (const string &s1, const string &s2) {
	for (unsigned i = 0; i < min(s1.length(), s2.length()); i++)
		if (!C::eq(s1[i], s2[i])) return C::lt(s1[i], s2[i]) ? -1 : 1;
	return (int) (s1.length() - s2.length());
}

int main () {

	string str1("Text");
	string str2("text");

	cout << "Regular comparison (Cmp)" << endl;
	cout << "Strings: '" << str1 << "' and '" << str2 << "' are ";
	cout << (cmp(str1, str2) ? "not " : "");
//	cout << (cmp<Cmp>(str1, str2) ? "not " : "");
	cout << "equal" << endl;
	cout << endl;

	cout << "Case insensitive comparison (Cmp_insensitive)" << endl;
	cout << "Strings: '" << str1 << "' and '" << str2 << "' are ";
	cout << (cmp<Cmp_insensitive>(str1, str2) ? "not " : "");
	cout << "equal" << endl;

	return EXIT_SUCCESS;
}

