#include <iostream>
using namespace std;

void handler (int test) {
	cout << "test = " << test << ": ";
	try {
		if (test == 0) throw invalid_argument("test == 0");
		else throw exception();
	} catch (invalid_argument& e) {
		cout << e.what() << endl;
	} catch (...) {
		cout << "Caught some other exception: " << endl;
	}
}

int main () {
	cout << "Start" << endl;
	handler(1);
	handler(2);
	handler(0);
	handler(3);
	handler(4);
	cout << "End" << endl;
	return 0;
}

