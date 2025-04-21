#include <iostream>
using namespace std;

void t_printf(const char* format) {
	cout << format;
}

template<typename T, typename... T_args>
void t_printf(const char* format, T value, T_args... F_args) {
	for(; *format; format++) {
		if(*format == '%') {
			cout << value;
			t_printf(format + 1, F_args...); // recursive call
			return;
		}
		cout << *format;
	}
}

int main() {
	t_printf("%, world% %\n", "Hello", '!', 1234);
	return EXIT_SUCCESS;
}

