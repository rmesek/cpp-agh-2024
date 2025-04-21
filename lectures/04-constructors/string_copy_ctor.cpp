/* Use of a copy constructor
 * The copy constructor is used in initializations:
 * -- initialization in definition
 * -- when passed as a parameter to a function (by value);
 * -- when a temporary object is created when used 
 *		as a return value of a function
 *
 * The copy constructor does NOT affect assignment operator.
 */

#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class String {

public:
	explicit String (const char *s = "") {
		init(s);
	}

// default copy constructor performs shallow copy
// to get a deep copy we have to implement custom copy ctor

//	String (const String& str) {
//		cout << "Copy ..." << endl;
//		init(str.string);
//	}

	~String() { 
		cout << "~String(): ";
		print();
		delete [] string;
	}

	void change(char c) {
		if(string && *string) string[0] = c;
	}

	void print() const {
		cout << quoted(string) << ": " << length << endl;
	}

private:
	int length{};
	char *string{};
	void init (const char*);
};

void String::init (const char *s) {
	length = (int)strlen(s);
	string = new char[length+1];
	strcpy (string, s);
}

String show_ext(String s) {
	s.print();
	cout << endl;
	cout << "Function return";
	cout << endl;
	return s;
}

int main () {
	String s1 ("Hello");
	cout << "Initialization" << endl;
	String s2 = s1;
	s1.print();
	s2.print();

	s2.change('h');
	cout << "After change() ..." << endl;
	s1.print();
	s2.print();
	cout << endl;

	cout << "Function call" << endl;
	show_ext(s1).print();
	return EXIT_SUCCESS;
}

