#include <iostream>
#include <cstring>
using namespace std;

class intArray {

public:
	explicit intArray(int sz, const int* p_array = nullptr) : sz{sz} {
		if(p_array) memcpy(array, p_array, sz * sizeof(int));
	}

	[[nodiscard]]
	int get_size() const { return sz; }

//	operator [] is inherited by Derived class
	int operator[](int index) const {
		return array[index];
	}

//	operator << cannot be inherited since it is not ptr member function
//	It works because of the parameter type conversion
//	(const NamedArray& -> const intArray&)
	friend ostream& operator<<(ostream& out, const intArray& p_array) {
		out << "<";
		for (int i = 0; i < p_array.sz; i++)
			out << p_array.array[i] << ((i == p_array.sz - 1) ? ">" : ", ");
		return out;
	}

private:
	static constexpr int DIM{5};
	int sz, array[DIM]{};
};

class NamedArray : public intArray {

public:
	explicit NamedArray (int sz, const int* a = nullptr, string s = ""s) :
			intArray(sz, a), name{std::move(s)} {}

private:
	string name;
};

void print_array(const intArray &array, const string &name) {
	cout << name << ", [] operator" << endl;
	cout << "<";
	for (int i = 0; i < array.get_size(); i++)
		cout << array[i] << ((i == array.get_size() - 1) ? ">" : ", ");
	cout << endl;
	cout << endl;

	cout << name << ", << operator" << endl;
	cout << array << endl;
	cout << endl;
}

int main () {
	int tmp_array[] {1, 3, 7, 4, 9};
	const int sz = sizeof tmp_array / sizeof tmp_array[0];

	intArray int_array(sz, tmp_array);
	print_array(int_array, "intArray");

	NamedArray named_array(sz, tmp_array, "NamedArray");
	print_array(named_array, "NamedArray");

	return EXIT_SUCCESS;
}

