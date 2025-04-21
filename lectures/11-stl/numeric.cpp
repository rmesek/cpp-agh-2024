#include <iostream>
#include <numeric>
#include <vector>
using namespace std;

int main() {
	vector<int> u(5);
	vector<int> v(u.size());

	iota(u.begin(), u.end(), 1);	//	1, 2, 3, 4, 5
	iota(v.begin(), v.end(), 11);	//	11, 12, 13, 14, 15

	int sum_u = accumulate(u.begin(), u.end(), 0);
	int product_u = accumulate(u.begin(), u.end(), 1,
			   [](auto a, auto b) { return a * b; });
	int inner = inner_product(u.begin(), u.end(), v.begin(), 0);

	cout << "sum_u = " << sum_u << endl;
	cout << "product_u = " << product_u << endl;
	cout << "inner product = " << inner << endl;

    vector<int> vj(u.size());

    // vj_i = sum(u_k, k = 0, ..., i)
    partial_sum(u.begin(), u.end(), vj.begin());
	for(int val : vj) cout << val << " ";
	cout << endl;
    partial_sum(u.begin(), u.end(), vj.begin(),
            [](auto a, auto b) { return a * b; });
	for(int val : vj) cout << val << " ";
	cout << endl;

	return 0;
}

