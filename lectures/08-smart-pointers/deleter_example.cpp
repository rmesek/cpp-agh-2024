#include <iostream>
#include "../includes/deleter_defs.h"
using namespace std;

// Why and when would we need custom deleter?
// Case 1: In order to fully delete an object sometimes, we need to do some
//		additional action. What if performing "delete" (that smart pointers do
//		automatically) is not the only thing which needs to be done before fully
//		destroying the owned object.
// Case 2: We can’t bind a shared_ptr or unique_ptr to a stack-allocated object,
//		because calling delete on it would cause undefined behaviour.
// Case 3: Mix of programming languages code, such as C++ with Obj-C.
//		As objective-c may need a complex release mechanism for its data types
//		such as calling CFRelease, we would be in need of a custom deleter.
// Case 4: In C where, when you wrap FILE*, or some kind of C style structure free(),
//		custom deleter may be useful.

int main() {
	int n = 12;
	{
		auto int_heap_ptr = make_unique_delete(new int(24));
		auto int_stack_ptr = make_unique_no_delete(&n);
		cout << *int_heap_ptr << endl;
		cout << *int_stack_ptr << endl;
		cout << endl;

		*int_heap_ptr = 56;
		*int_stack_ptr = 67;
		cout << *int_heap_ptr << endl;
		cout << *int_stack_ptr << endl;
	}
	cout << endl;

	{
	string str("stack"s);
	auto s_heap_ptr = make_unique_delete(new string("heap"s));
	auto s_stack_ptr = make_unique_no_delete(&str);
	cout << *s_heap_ptr << endl;
	cout << *s_stack_ptr << endl;
	}

	return EXIT_SUCCESS;
}

