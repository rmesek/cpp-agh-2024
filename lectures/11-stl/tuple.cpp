#include <iostream>
#include <tuple>

using namespace std;

tuple<double, char, string> get_student(int id) {
	switch (id) {
		case 0:
			return make_tuple(3.8, 'A', "Lisa Simpson");
		case 1:
			return make_tuple(2.9, 'C', "Mary Johnson");
		case 2:
			return make_tuple(1.7, 'D', "Ralph Williams");
		default:
			throw invalid_argument("id");
	}
}

void print_tuple(double gpa, char grade, string name) {
	cout<< "name: " << name << ", "
		<< "GPA: " << gpa << ", "
		<< "grade: " << grade << endl;
}

int main() {
	auto student = get_student(0);
	print_tuple(get<0>(student), get<1>(student), get<2>(student));

	// C++17 structured binding:
	auto [ gpa1, grade1, name1 ] = get_student(1);
	print_tuple(gpa1, grade1, name1);
	auto [ gpa2, grade2, name2 ] = get_student(2);
	print_tuple(gpa2, grade2, name2);

	return 0;
}

