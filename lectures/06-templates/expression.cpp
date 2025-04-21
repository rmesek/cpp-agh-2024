#include <cstdio>

// necessary; otherwise folding expression wouldn't work
template<class...A>
void six_params(A...arg);

void six_params(int a1, int a2, int a3, int a4, int a5, int a6) { // specialization
	printf("six_params(%2d, %2d, %2d, %2d, %2d, %2d)\n", a1, a2, a3, a4, a5, a6);
}

template<class...A> int test_function(A...args) {
	int size = sizeof...(A);
	switch(size) {
		case 0:
			six_params(99, 99, 99, 99, 99, 99);
				break;
		case 1:
			six_params(99, 99, args..., 99, 99, 99);
				break;
		case 2:
			six_params(99, 99, args..., 99, 99);
				break;
		case 3:
			six_params(args..., 99, 99, 99);
				break;
		case 4:
			six_params(99, args..., 99);
				break;
		case 5:
			six_params(99, args...);
				break;
		case 6:
			six_params(args...);
				break;
		default:
			six_params(0, 0, 0, 0, 0, 0);
				break;
	}
	return size;
}

int main(){

	test_function();
	test_function(1);
	test_function(1, 2);
	test_function(1, 2, 3);
	test_function(1, 2, 3, 4);
	test_function(1, 2, 3, 4, 5);
	test_function(1, 2, 3, 4, 5, 6);
	test_function(1, 2, 3, 4, 5, 6, 7);

	return RENAME_EXCHANGE;
}

