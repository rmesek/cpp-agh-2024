#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

//	All containers have the following methods:
//	size() - size of the container
//	swap() - swap contents of two containers
//	begin() - iterator to the 1st element
//	end() - iterator pointing AFTER the last element
//	* - get element pointer_type by iterator
//	++ - point to the next element
//
//	class vector has additionally:
//	= - assignment operator
//	[] - indexing
//	dynamic memory allocation

template <class T>
void print(const vector<T>& v, const string& s) {
	cout << s << ": size() = " << v.size() << " capacity() = " << v.capacity() << endl;
	for(auto e : v) cout << e << " ";
//	for_each(v.begin(), v.end(), [](const auto& e) { cout << e << " "; });
//	for(auto i = 0; i < (int)v.size(); ++i) cout << v[i] << " ";
//	for(auto it = v.begin(); it != v.end(); ++it) cout << *it << " ";
	cout << endl;
}

int main() {
	constexpr int N = 5;

//	make room for 5 ints, and initialize them to 0
	vector<int> v(N);
	print(v, "vector<Integer> v(N)");
	iota(v.begin(), v.end(), 1);
	print(v, "vector<Integer> iota()");
	cout << endl;

	//	at() throws exception on index out of bounds
	try {
        v.at(10) = 0;
	} catch(const exception& e) {
		cout << e.what() << endl;
	}
	cout << endl;

	v.clear();	//	remove all elements
	print(v, "vector.clear()");

	for(int i = 0; i < N; i++) {
		v.emplace_back(i + 20);
	}

	print(v, "v.emplace_back()...");
	cout << endl;

//	The correct way of enlarging the number of contained elements is to call
//	vector's member function resize(). The member function resize() has
//	following properties:

//	If the new size is larger than the old size of the vector, it will preserve
//	all elements already present in the controlled sequence; the rest will be
//	initialized according to the second parameter.

//	If the new size is smaller than the old size, it will preserve only the
//	first new_size elements. The rest is discarded and shouldn't be used
//	anymore - consider these elements invalid.

//	If the new size is larger than capacity(), it will reallocate storage so
//	all new_size elements fit. resize() will never shrink capacity().

//	resize the vector; at this point, the vector contains
//	20 21 22 23 24 0 0 0 0 0
	v.resize(10);
	print(v, "v.resize(10)");
	cout << endl;

//	resize the vector; at this point, the vector contains
//	20 21 22
	v.resize(3);
	print(v, "v.resize(3)");
	cout << endl;

//	resize again, fill up with ones; at this point, the vector contains
//	20 21 22 1 1 1
	v.resize(6, 1);
	print(v, "v.resize(6, 1)");
	cout << endl;


//	shrink_to_fit() - shrink capacity to fit size
	v.shrink_to_fit();
	print(v, "v.shrink_to_fit");

	return EXIT_SUCCESS;
}

