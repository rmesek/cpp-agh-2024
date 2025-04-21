#include <iostream>
using namespace std;

class OneInt {

public:
	explicit OneInt(int n_1 = 0) : n_1(n_1) {}
	virtual ~OneInt() = default;
	virtual void show() { cout << "n_1 = " << n_1 << endl; }
	virtual OneInt& operator++() {
		n_1++;
		cout << "Base increment \n";
		return *this;
	}

protected:
	int n_1;
};

class TwoInts : public OneInt {

public:
	explicit TwoInts(int n_1 = 0, int n_2 = 0) : OneInt(n_1), n_2(n_2) {}
	void show() override {
		OneInt::show();
		cout << "n_2 = " << n_2 << endl;
	}
	OneInt& operator++() override {
		n_1++;
		n_2++;
		cout << "Derived increment \n";
		return *this;
	}

private:
	int n_2;
};

int main() {
	TwoInts two_ints(1, 4);
	OneInt& one_int_reference{two_ints};

	two_ints.show();
	cout << endl;

	++one_int_reference;
	one_int_reference.show();
	cout << endl;

	(++one_int_reference).show();

	return EXIT_SUCCESS;
}

