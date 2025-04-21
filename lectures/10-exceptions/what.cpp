#include <iostream>
using namespace std;

class my_exception : public runtime_error {
public:
	explicit my_exception(const string& what_arg) : runtime_error(what_arg) {}
	~my_exception() override = default;
};

void f() {
	throw my_exception("child description");
}

int main() {
	try {
		f();
	} catch(exception e) {
		cout << "e.what=[" << e.what() << "]" << endl;
	}

	try {
		f();
	} catch(exception& e) {
		cout << "e.what=[" << e.what() << "]" << endl;
	}
	return 0;
}

