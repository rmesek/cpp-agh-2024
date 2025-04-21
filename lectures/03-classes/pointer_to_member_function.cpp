#include <iostream>
#include <vector>
using namespace std;

class Bird {
public:
	using bird_fnc_ptr = void (Bird::*)() const;
	explicit Bird(string name) : name{std::move(name)} {}
	void choose() {
		for (auto& ptr : p2f) {
			(this->*ptr)();
		}
	}

private:
	string name;
	void fly() const { cout << name << ": is flying..." << endl; }
	void chirp() const { cout << name <<": twitter...tweet" << endl;}
	void hop() const { cout << name <<": hop...hop" << endl;}
	void peck() const { cout << name <<": pick...pick" << endl;}
	vector<bird_fnc_ptr> p2f { &Bird::fly, &Bird::chirp, &Bird::hop, &Bird::peck };
};

int main() {
	Bird bird{"Chickadee"s};
	bird.choose();

	return EXIT_SUCCESS;
}

