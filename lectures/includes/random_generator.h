#ifndef CPP_PURE_RANDOM_GENERATOR_H
#define CPP_PURE_RANDOM_GENERATOR_H

#include <random>

class randomize {
public:
	static std::mt19937 mersenne_engine;

	template<std::integral T>
	static T random_int(T _min, T _max) {
		std::uniform_int_distribution<T> d(_min, _max);
		return d(mersenne_engine);
	}

	template<std::floating_point T>
	static T random_float(T _min, T _max) {
		std::uniform_real_distribution<T> d(_min, _max);
		return d(mersenne_engine);
	}
};

std::mt19937 randomize::mersenne_engine{std::mt19937{std::random_device{}()}};

#endif //CPP_PURE_RANDOM_GENERATOR_H
