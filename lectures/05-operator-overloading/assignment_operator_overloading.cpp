#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

class String {
public:
	explicit String(const char *src = "") {
		init(src);
	}

	String(const String& src) {
		cout << "Copy ... \n"; 
		init(src.string);
	}

	String(String&& src) noexcept : string{src.string} {
		cout << "Move ... " << string << endl;
		src.string = nullptr;
	}

	~String() { 
		cout << "~String: ";
		print(cout);
		free(string); // since strdup uses malloc()
	}

	String& operator=(const String& other_string) {
		cout << "Copy assignment ..." << endl;
// make sure that the objects are not the same
// otherwise we would delete the rhs array!!!
		if(this == &other_string) return *this;
		free(string);
		init(other_string.string);
//	needed since operator = has a value!!!
		return *this;
	}

	String& operator=(String&& other_string) noexcept {
		cout << "Move assignment ..." << endl;
		if(this == &other_string) return *this;
		free(string);
		this->string = other_string.string;
		other_string.string = nullptr;
		return *this;
	}

	ostream& print(ostream &os) const {
		if(string != nullptr) {
			return os << quoted(string) << ": " << strlen(string) << endl;
		}
		return os << "null string" << endl;
	}

private:
	char *string{};
	void init(const char *src) {
		string = strdup(src);
	}
};

ostream &operator<<(ostream &os, const String &str) {
	return str.print(os);
}

void print_strings(const vector<String> &strings) {
	for (const String &string : strings) {
		cout << string;
	}
	cout << endl;
}

int main () {

	vector<String> strings;
	strings.reserve(3); // allocates 3 elements;
	strings.emplace_back("Short");
	strings.emplace_back("LongString");
	strings.emplace_back("AnotherString");
	print_strings(strings);

	strings[0] = strings[1];
	print_strings(strings);

	strings[2] = std::move(strings[1]);
	print_strings(strings);

	return EXIT_SUCCESS;
}

