#include <iostream>
using namespace std;

//	The original intent of the inline keyword was to serve as an indicator to
//	the optimizer that inline substitution of a function is preferred over
//	function call, that is, instead of executing the function call CPU
//	instruction to transfer control to the function body, a copy of the function
//	body is executed without generating the call. This avoids overhead created
//	by the function call (copying the arguments and retrieving the result) but
//	it may result in a larger executable as the code for the function has to be
//	repeated multiple times.

//	Since this meaning of the keyword inline is non-binding, compilers are free
//	to use inline substitution for any function that's not marked inline, and
//	are free to generate function calls to any function marked inline. Those
//	optimization choices do not change the rules regarding multiple definitions
//	and shared statics listed above. 

//	An inline function has the following properties:

//	1) There may be more than one definition of an inline function in the
//	program as long as each definition appears in a different translation unit
//	and all definitions are identical. For example, an inline function may be
//	defined in a header file that is #include'd in multiple source files.

//	2) The definition of an inline function must be present in the translation
//	unit where it is accessed (not necessarily before the point of access).

//	3) An inline function with external linkage (e.g.
//	not declared static) has the following additional properties:

//	a) It must be declared inline in every translation unit.
//	b) It has the same address in every translation unit.

inline bool even (int x) {
	return !(x & 1);
}

inline double min (double a, double b) {
	return a < b ? a : b;
}

int main () {

	if (even(10)) cout << "10 is even" << endl;
	else cout << "10 is not even" << endl;
	if (even(11)) cout << "11 is even" << endl;
	else cout << "11 is not even" << endl;

	cout << "min (10., 3.) is " << min(10.,3.) << endl;
	cout << "min (10., 3) is " << min(10.,3) << endl;
	cout << "min (10, 3) is " << min(10,3) << endl;

	return EXIT_SUCCESS;
}

