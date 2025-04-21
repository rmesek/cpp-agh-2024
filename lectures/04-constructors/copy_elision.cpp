//	Copy elision happens whenever an object is initialized by copying another
//	object of the same type, and the source object is no longer accessible
//	afterward, e.g. leave current scope. In this case, compiler treats it as
//	two objects are holding the same place, just skip the copy constructor and
//	replace the place with the new name. There are two major cases where copy
//	elision would happen: returning a local variable inside a function, and
//	initializing a variable with a temporary value.

//	Copy elision is an optional optimization until C++17, and in C++17 it
//	is mandatory in certain cases.

#include<iostream>
using namespace std;

string change() { // return by value !!!
	string local_str{"lower case"};
	for(auto& c: local_str) c = (char)toupper(c);
	cout << "&local_str = " << &local_str << endl;
	cout << " local_str = " <<  local_str << endl;
	return local_str;
}

int main() {
	string out_str = change();
	cout << "&out_str   = " << &out_str << endl; // the same address as local in change()!!!
	cout << " out_str   = " <<  out_str << endl;

	return EXIT_SUCCESS;
}

//	Thanks to copy elision, the out_str will take the ownership of the local
//	variable right after the function exits, it’s completely free.

