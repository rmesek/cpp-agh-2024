#include <iostream>
#include <functional>
using namespace std;

//	std::function is a templated object that is used to store and call any
//	callable type, such as functions, objects, lambdas and the result of
//	std::bind.

void global_function() {
	cout << "global_function()" << endl;
}

struct Functor {
	void operator()() { cout << "Functor()" << endl; }
};

void execute(const function<void()> &f) {
	f();
}

int main() {
	execute(global_function);
	execute(Functor{});
	execute([] { cout << "lambda()" << endl; });

	return EXIT_SUCCESS;
}

