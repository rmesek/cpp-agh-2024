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

Talk glob ("Global");

int main () {
	cout << "main() begin" << endl;
	{
		Talk local ("Local");
	}
	Talk *p_talk = new Talk ("New");
	delete p_talk;
	cout << "main() end" << endl;

	return EXIT_SUCCESS;
}

