#define FMT_HEADER_ONLY
#include <fmt/ranges.h>
#include <deque>
using namespace std;
using namespace fmt;

//	deque (double-ended queue) is an indexed sequence container that allows
//	fast insertion and deletion at both its beginning and its end. In addition,
//	insertion and deletion at either end of a deque never invalidates pointers
//	or references to the rest of the elements.

//	As opposed to vector, the elements of a deque are not stored contiguously:
//	typical implementations use a sequence of individually allocated fixed-size
//	arrays.

//	The storage of a deque is automatically expanded and contracted as needed.
//	Expansion of a deque is cheaper than the expansion of a vector because it
//	does not involve copying of the existing elements to a new memory location.

//	The complexity (efficiency) of common operations on deque is as follows:

//	Random access - constant O(1)
//	Insertion or removal of elements at the end or beginning - amortized constant O(1)
//	Insertion or removal of elements - linear O(n) 

template <class T>
void print(const deque<T>& dq) {
	println("{}", dq);
}

int main() { 
//	create an empty deque and fill with ints using push_back()
	deque<int> dq;
	for (int i = 0; i < 5; ++i) dq.push_back(i);
	print(dq);

//	add 3 copies of the number to the front of the deque using push_front()
	for (int i = 0; i < 3; ++i) dq.push_front(8);
	print(dq);

//	remove first and last elements with pop_back() and pop_front()
	dq.pop_front();
	dq.pop_back();
	print(dq);

//	insert some elements using iterators
	dq.insert(dq.begin() + 2, { 10, 11, 12 });
	print(dq);

	return EXIT_SUCCESS;
}

