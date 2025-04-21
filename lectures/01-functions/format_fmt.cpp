#define FMT_HEADER_ONLY
//#include <fmt/format.h>
#include <fmt/ranges.h> // instead of format.h to print collections
#include <vector>
#include <set>
#include <list>
#include <map>
#include <cmath>
using namespace fmt;
using namespace fmt::literals;
using namespace std;


void argument_placeholder() {
	auto m{7}, n{10};
	println("n = {}", n); // n = 10
	println("{} out of {}", m, n); // 7 out of 10
	println("{{braces}}"); // {braces}
	println("");
}

void indexing_arguments() {
	int n{5};
	println("{0}{0}", n); // 55
	println("{1} & {0}", 10, 20); // 20 & 10
	println("{m}x", arg("m", 8)); // 8x
	println("-{m}", "m"_a = 8); // -8
	println("");
}

void integers() {
	int n{18}, w{6};

	println("{}", n); // 18

	println("{:-} {:-}", -n, n); // -18 18
	println("{:+} {:+}", -n, n); // -18 +18
	println("{: } {: }", -n, n); // -18  18

	// fill-and-align is an optional fill character (which can be any
	// character other than { or }), followed by one of the align options
	// <, >, ^. The meaning of align options is as follows:

	// <: Forces the field to be aligned to the start of the available space.
	//      This is the default when a non-integer non-floating-point presentation type is used.
	// >: Forces the field to be aligned to the end of the available space.
	//      This is the default when an integer or floating-point presentation type is used.
	// ^: Forces the field to be centered within the available space by inserting ⌊n/2⌋ characters
	//      before and ⌈n/2⌉ characters after
	println("{:6}", n);       // ....18
	println("{:06}", n);      // 000018
	println("{0:{1}}", n, w); // ....18
	println("{:>6}", n);      // ....18
	println("{:*>6}", n);     // ****18
	println("{:*^6}", n);     // **18**
	println("{:*<6}", n);     // 18****

	println("{:b}", n);       // 10010
	println("{:#b}", n);      // 0b10010
	println("{:x}", n);       // 12
	println("{:#x}", n);      // 0x12
	println("{:o}", n);       // 22
	println("{:#o}", n);      // 022

	println("");
}

void floats() {
	double d{10*M_PI};
//	double d{34.591};

	println("{}", d);      // 31.41592653589793 - as many as needed
	println("{:g}", d);    // 31.4159 - default precision 6

	println("{:.0}", d);   // 3e+01
	println("{:.1}", d);   // 3e+01
	println("{:.2}", d);   // 31
	println("{:.3}", d);   // 31.4
	println("{:8.3}", d);  // ....31.4
	println("{:08.3}", d); // 000031.4
	println("");

	println("{:f}", d);    // 31.415927
	println("{:F}", d);    // 31.415927
	println("{:.0f}", d);  // 31
	println("{:.1f}", d);  // 31.4
	println("{:.2f}", d);  // 31.42
	println("{:.3f}", d);  // 31.416
	println("");

	println("{:e}", d);    // 3.141593e+01
	println("{:E}", d);    // 3.141593E+01
	println("{:.0e}", d);  // 3e+01
	println("{:.1e}", d);  // 3.1e+01
	println("{:.2e}", d);  // 3.14e+01
	println("{:.3e}", d);  // 3.142e+01

	println("{:*>+12.1e}", d);         // ****+3.1e+01
	println("{:*>+{}.{}e}", d, 12, 1); // ****+3.1e+01

	println("");
}

void collections() {
	println("vector: {}", vector{ 1, 2, 3, 4, 5 });
	println("vector: {::#x}", vector{ 1, 2, 3, 4, 5 });
	println("vector: {}", join(vector{ 1, 2, 3, 4, 5 }, " - "));
	println("{}", vector{'h', 'e', 'l', 'l', 'o'}); // ['h', 'e', 'l', 'l', 'o']
	println("{::}", vector{'h', 'e', 'l', 'l', 'o'}); // [h, e, l, l, o]
	println("{::d}", vector{'h', 'e', 'l', 'l', 'o'}); // [104, 101, 108, 108, 111]
	println("list: {}", list{ 1, 2, 3, 4, 5 });
	println("set: {}", set{ 1, 2, 3, 4, 5 });
	println("map: {}", map<int, string> {{1, "1"}, {2, "2"}, {3, "3"}});

	println("");
}

int main() {
	argument_placeholder();
	indexing_arguments();
	integers();
	floats();
	collections();

	// bonus :)
	fmt::println(
		"┌{0:─^{2}}┐\n"
		"│{1: ^{2}}│\n"
		"└{0:─^{2}}┘\n", "", "Hello, world!", 20);

	return EXIT_SUCCESS;
}

