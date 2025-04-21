#include <iostream>
using namespace std;

int main() {
	constexpr long MAX = 1000000000;
	int *big;
	try {
		for (int i = 0; ; i++) {
			big = new int[MAX];
			cout << i+1 << " * " << MAX << " allocated: " << big << endl;
		}
	} catch (exception &e) {
		cout << "Exception: " << e.what() << endl;
	}
	return 0;
}

