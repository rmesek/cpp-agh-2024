#ifndef SMART_POINTERS_DELETER_DEFS_H
#define SMART_POINTERS_DELETER_DEFS_H
#include <memory>

template<typename T>
auto make_unique_delete(T* p) { // create ptr to object on heap
	// default deleter (for objects on heap)
	auto do_delete = [](const auto* p) {
		std::cout << "object deleted" << std::endl;
		delete p;
	};
    return std::unique_ptr<T, decltype(do_delete)>(p, do_delete);
}

template<typename T>
auto make_unique_no_delete(T* p) { // create ptr to object on stack
	// empty deleter (for objects on stack)
	auto do_not_delete = [](const auto*) {
		std::cout << "empty deleter" << std::endl;
	};
	return std::unique_ptr<T, decltype(do_not_delete)>(p, do_not_delete);
}

#endif // SMART_POINTERS_DELETER_DEFS_H
