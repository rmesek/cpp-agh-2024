#include <format>
#include <cmath>
#include <iostream>
using namespace std;

void argument_placeholder() {
	auto m{7}, n{10};
	cout << format("n = {}", n) << endl; // n = 10
	cout << format("{} out of {}", m, n) << endl; // 7 out of 10
	cout << format("{{braces}}") << endl; // {braces}
	cout << endl;
}

void indexing_arguments() {
	int n{5};
	cout << format("{0}{0}", n) << endl; // 55
	cout << format("{1} & {0}", 10, 20) << endl; // 20 & 10
	cout << endl;
}

void integers() {
	int n{18}, w{6};

	cout << format("{}", n) << endl; // 18

	cout << format("{:-} {:-}", -n, n) << endl; // -18 18
	cout << format("{:+} {:+}", -n, n) << endl; // -18 +18
	cout << format("{: } {: }", -n, n) << endl; // -18  18

	// fill-and-align is an optional fill character (which can be any
	// character other than { or }), followed by one of the align options
	// <, >, ^. The meaning of align options is as follows:

	// <: Forces the field to be aligned to the start of the available space.
	//      This is the default when a non-integer non-floating-point presentation type is used.
	// >: Forces the field to be aligned to the end of the available space.
	//      This is the default when an integer or floating-point presentation type is used.
	// ^: Forces the field to be centered within the available space by inserting ⌊n/2⌋ characters
	//      before and ⌈n/2⌉ characters after
	cout << format("{:6}", n) << endl;       // ....18
	cout << format("{:06}", n) << endl;      // 000018
	cout << format("{0:{1}}", n, w) << endl; // ....18
	cout << format("{:>6}", n) << endl;      // ....18
	cout << format("{:*>6}", n) << endl;     // ****18
	cout << format("{:*^6}", n) << endl;     // **18**
	cout << format("{:*<6}", n) << endl;     // 18****
	cout << endl;

	cout << format("{:b}", n) << endl;       // 10010
	cout << format("{:#b}", n) << endl;      // 0b10010
	cout << format("{:x}", n) << endl;       // 12
	cout << format("{:#x}", n) << endl;      // 0x12
	cout << format("{:o}", n) << endl;       // 22
	cout << format("{:#o}", n) << endl;      // 022
	cout << endl;
}

void floats() {
	double d{10*M_PI};

	cout << format("{}", d) << endl;      // 31.41592653589793 - as many as needed
	cout << format("{:g}", d) << endl;    // 31.4159 - default precision 6

	cout << format("{:.0}", d) << endl;   // 3e+01
	cout << format("{:.1}", d) << endl;   // 3e+01
	cout << format("{:.2}", d) << endl;   // 31
	cout << format("{:.3}", d) << endl;   // 31.4
	cout << format("{:8.3}", d) << endl;  // ....31.4
	cout << format("{:08.3}", d) << endl; // 000031.4
	cout << endl;

	cout << format("{:f}", d) << endl;    // 31.415927
	cout << format("{:F}", d) << endl;    // 31.415927
	cout << format("{:.0f}", d) << endl;  // 31
	cout << format("{:.1f}", d) << endl;  // 31.4
	cout << format("{:.2f}", d) << endl;  // 31.42
	cout << format("{:.3f}", d) << endl;  // 31.416
	cout << endl;

	cout << format("{:e}", d) << endl;    // 3.141593e+01
	cout << format("{:E}", d) << endl;    // 3.141593E+01
	cout << format("{:.0e}", d) << endl;  // 3e+01
	cout << format("{:.1e}", d) << endl;  // 3.1e+01
	cout << format("{:.2e}", d) << endl;  // 3.14e+01
	cout << format("{:.3e}", d) << endl;  // 3.142e+01

	cout << format("{:*>+12.1e}", d) << endl;         // ****+3.1e+01
	cout << format("{:*>+{}.{}e}", d, 12, 1) << endl; // ****+3.1e+01

	cout << endl;
}

int main() {
	argument_placeholder();
	indexing_arguments();
	integers();
	floats();

	return EXIT_SUCCESS;
}

