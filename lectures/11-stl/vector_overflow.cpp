#include <vector>
#include <iostream>
using namespace std;

class Noisy {

public:
	Noisy() : id(create++) { 
		cout << "ct[" << id << "]";
	}
	Noisy(const Noisy& noisy) : id(noisy.id) {
		cout << "cp[" << id << "]";
		copy_ctor++;
	}
    Noisy(Noisy&& noisy)  noexcept : id(noisy.id) {
        cout << "mv[" << id << "]";
        move_ctor++;
    }
	Noisy& operator=(const Noisy& noisy) {
		cout << "(" << id << ")=[" << noisy.id << "]";
		id = noisy.id;
		assign++;
		return *this;
	}
	~Noisy() {
		cout << "~[" << id << "]";
		destroy++;
	}
	friend class NoisyReport;

private:
	static long create, assign, copy_ctor, destroy, move_ctor;
	long id;
};

class NoisyReport {
	static NoisyReport nr;	//	a hack to create NoisyReport static object
public:
	~NoisyReport() {
		cout << endl;
		cout << endl;
		cout << "cleaning up" << endl;
		cout << "-------------------" << endl;
		cout << "Noisy creations: " << Noisy::create << endl;
		cout << "Copy-Constructions: " << Noisy::copy_ctor << endl;
		cout << "Move-Constructions: " << Noisy::move_ctor << endl;
		cout <<	"Assignments: " << Noisy::assign << endl;
		cout << "Destructions: " << Noisy::destroy << endl;
		cout << endl;
	}
};

long Noisy::create{}, Noisy::assign{}, Noisy::move_ctor{};
long Noisy::copy_ctor{}, Noisy::destroy{};
NoisyReport NoisyReport::nr;

int main() {
	constexpr int size = 10;
	vector<Noisy> vn;
	for (int i = 0; i < size; i++) {
		cout << "inserting element " << i;
		cout << ": " << vn.size() << " " << vn.capacity() << " "; // << endl;
		vn.emplace_back();
		cout << endl;
	}
	cout << "------------------------------------" << endl;
	return 0;
}

