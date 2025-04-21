#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <execution>

using namespace std;

vector<int> generate_data(size_t size) {
	static mt19937 mersenne_engine {random_device{}()}; // Generates random integers
	static uniform_int_distribution<int> dist {1, 100};
	std::vector<int> data(size);
	std::generate(data.begin(), data.end(), [] { return dist(mersenne_engine); });
	return data;
}

template <typename TFunc> void run_and_measure(const char* title, TFunc func) {
	const auto start = chrono::steady_clock::now();
	func();
	const auto end = chrono::steady_clock::now();
	std::cout << title << ": " << chrono::duration <double, std::milli>(end - start).count()
		<< " ms" << endl;
}

int main() {
	vector<int> v_orig = generate_data(10000000);

// standard sequential sort
	vector v {v_orig};
	run_and_measure("standard", [&v] {
		sort(v.begin(), v.end());
	});

// explicitly sequential sort
	v = v_orig;
	run_and_measure("execution::seq", [&v] {
		sort(execution::seq, v.begin(), v.end());
	});

// permitting parallel execution
	v = v_orig;
	run_and_measure("execution::par", [&v] {
		sort(execution::par, v.begin(), v.end());
	});

// permitting vectorization as well
	v = v_orig;
	run_and_measure("execution::unseq", [&v] {
		sort(execution::unseq, v.begin(), v.end());
	});
}

