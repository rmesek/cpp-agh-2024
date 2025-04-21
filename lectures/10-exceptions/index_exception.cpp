#include<iostream>
using namespace std;

class Array {

public:
	class index_exception : public out_of_range {
	public:
		index_exception(const string& what_arg, int index)
			: out_of_range(what_arg + ": " + to_string(index)) {}
	};

	Array() {
		for(int i = 0; i < SIZE; ++i) array[i] = i;
	}
	int& operator[](int i) {
		if(i >= 0 && i < SIZE) return array[i];
		throw index_exception("Index out of bounds exception", i);
	}
	ostream &print(ostream& o) const {
		for(int v : array) o << v << " ";
		return o << endl;
	}

private:
	static constexpr int SIZE = {5};
	int array[SIZE]{};
};

ostream& operator<<(ostream& o, const Array& a) {
	return a.print(o);
}

int main() {
	Array array;
	cout << array;
	try {
		for(int i = 0; ; ++i) {
			cout << array[i] << " ";
		}
	} catch(Array::index_exception& e) {
		cout << endl;
		cout << e.what() << endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

