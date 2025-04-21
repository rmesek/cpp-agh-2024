#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// COMMON

//	empty() - returns true if queue empty
//	size() - returns number of elements in the queue
//	pop() - removes the first element (but does not return it)
//	push() - inserts element at the end of the queue

//	QUEUE

//	front() - returns the first element but does not remove it
//	back() - returns the last element but does not remove it

//	PRIORITY QUEUE

//	top() - returns the element with the highest priority but does not remove it

//	STACK

//	top() - returns the element from the top but does not remove it

int main() {
	const auto data = {1, 8, 5, 6, 3, 4, 0, 9, 7, 2};

	queue<int> q(data.begin(), data.end());
	cout << "Queue: ";
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;

	priority_queue<int> pq_less(data.begin(), data.end());
	cout << "Priority queue(std::less): ";
	while (!pq_less.empty()) {
		cout << pq_less.top() << " ";
		pq_less.pop();
	}
	cout << endl;

	priority_queue pq_greater(data.begin(), data.end(), std::greater<int>());
//	priority_queue<int, vector<int>, decltype(std::greater<int>())> pq_greater(data.begin(), data.end());
	cout << "Priority queue(std::greater): ";
	while (!pq_greater.empty()) {
		cout << pq_greater.top() << " ";
		pq_greater.pop();
	}
	cout << endl;

	auto custom_comparator = [](int left, int right) { return (left ^ 1) < (right ^ 1); };
	priority_queue pq_custom(data.begin(), data.end(), custom_comparator);
//	priority_queue<int, vector<int>, decltype(custom_comparator)> pq_custom(data.begin(), data.end(), custom_comparator);
	cout << "Priority queue(custom): ";
	while (!pq_custom.empty()) {
		cout << pq_custom.top() << " ";
		pq_custom.pop();
	}
	cout << endl;

	stack<int> s(data.begin(), data.end());
	cout << "Stack: ";
	while (!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}

	return EXIT_SUCCESS;
}
	
