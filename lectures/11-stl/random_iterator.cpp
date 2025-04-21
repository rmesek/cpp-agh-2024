#include <iostream>
#include <vector>
#include <algorithm>
#include <ranges>
#include "../includes/random_generator.h"

template <typename T>
class Iterator {

public:
	using iterator_category = std::random_access_iterator_tag;
	using value_type      = T;
	using reference_type  = T&;
	using const_reference_type  = const T&;
	using pointer_type    = T*;
	using const_pointer_type    = const T*;
	using difference_type = std::iter_difference_t<T>;

	// All iterators must be constructible, copy-constructible, copy-assignable,
	// destructible and swappable.

	// The custom constructor satisfies the constructible requirement,
	// while all others are covered by the implicitly-declared constructors
	// and operators kindly provided by the compiler.

	Iterator() = default;
	explicit Iterator(pointer_type ptr) : ptr(ptr) {}

	// dereferenceable
	reference_type operator* () const { return *ptr; }
	pointer_type   operator->() const { return  ptr; }

	// incrementable / decrementable
	Iterator& operator++()    { ptr++; return *this; }
	Iterator  operator++(int) { auto tmp{*this}; ++(*this); return tmp; }
	Iterator& operator--()    { ptr--; return *this; }
	Iterator  operator--(int) { auto tmp{*this}; --(*this); return tmp; }

	Iterator& operator+=(difference_type diff) {
		ptr += diff;
		return *this;
	}
	Iterator& operator-=(difference_type diff) {
		ptr -= diff;
		return *this;
	}

	difference_type operator-(const Iterator& it) const {
		return this->ptr - it.ptr;
	}

	reference_type operator[] (difference_type offset) const {
		return *(ptr + offset);
	}

	// comparable
	auto operator<=> (const Iterator& it) const = default;

	friend Iterator<T> operator+(difference_type n, Iterator<T> it) {
		return it + n;
	}

	friend Iterator<T> operator+(Iterator<T> it, difference_type n) {
		Iterator<T> temp{it};
		temp += n;
		return temp;
	}

	friend Iterator<T> operator-(Iterator<T> it, difference_type n) {
		Iterator<T> temp{it};
		temp -= n;
		return temp;
	}

private:
	pointer_type ptr{};
};

template <typename T>
class Y {

public:
	using iterator = Iterator<T>;
	using const_iterator = Iterator<const T>;
	using reverse_iterator = std::reverse_iterator<iterator>;
	using const_reverse_iterator = std::reverse_iterator<const_iterator>;

	[[nodiscard]]
	size_t size() const noexcept { return N; }

	// iterator
	iterator begin() { return iterator(&array[0]); }
	iterator end() { return iterator(&array[N]); }

	// const iterator
	[[nodiscard]]
	const_iterator cbegin() const { return const_iterator(&array[0]); }
	[[nodiscard]]
	const_iterator cend() const { return const_iterator(&array[N]); }

	// reverse iterator
	reverse_iterator rbegin() { return reverse_iterator(end()); }
	reverse_iterator rend() { return reverse_iterator(begin()); }

	// const reverse iterator
	[[nodiscard]]
	const_reverse_iterator crbegin() const {
		return const_reverse_iterator(cend());
	}
	[[nodiscard]]
	const_reverse_iterator crend() const {
		return const_reverse_iterator(cbegin());
	}

private:
	static constexpr size_t N{16};
//	T array[N];
	std::vector<T> array{std::vector<int>(N)};
};

void print_iterator(Y<int> &y) {
	for (int v : y) {
		std::cout << v << ' ';
	}
	std::cout << std::endl;

// The above is translated by the compiler into:
//	for (auto it = y.cbegin(); it != y.cend(); ++it) {
//		std::cout << *it << ' ';
//	}
}

void print_reverse(Y<int>& y) {
	for (int v : std::ranges::reverse_view(y)) {
		std::cout << v << ' ';
	}
	std::cout << std::endl;

//	for (auto it = y.rbegin(); it != y.rend(); ++it) {
//		std::cout << *it << ' ';
//	}
}

int main() {

	// check if the iterator fulfills all the requirements
	static_assert(std::random_access_iterator<Iterator<int>>);

	Y<int> y{};
	std::ranges::generate(y, [] { return randomize::random_int(0, 99); });
	print_iterator(y);

	std::ranges::sort(y, std::greater<>());
//	std::ranges::sort(y);
	print_iterator(y);
	print_reverse(y);

//	std::shuffle(y.begin(), y.end(), randomize::mersenne_engine );
	std::ranges::shuffle(y, randomize::mersenne_engine );
	print_iterator(y);

	auto it = std::ranges::min_element(y);
	std::cout << "min: " << *it << std::endl;
	*it = -1;
	it = y.begin();
	std::cout << "y[5] = " << it[5] << std::endl;
	std::cout << "y[5] = " << *(it + 5) << std::endl;
	print_iterator(y);

	std::cout << "count: " << std::ranges::count_if(y, [] (int i) { return i > 50; }) << std::endl;
}

