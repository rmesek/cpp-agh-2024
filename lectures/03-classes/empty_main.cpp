#include <iostream>
using namespace std;

class Talk {

public:
	explicit Talk (const string& name) : name{name} {
		cout << "I am " << name << endl;
	}

	~Talk() {
		cout << "Clean up " << name << endl;
	}

private:
	string name;
};

Talk global ("Global");

int main () {
    return EXIT_SUCCESS;
}

