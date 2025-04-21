#include <iostream>
#include <fstream>
#include <memory>
using namespace std;

void close_file(ifstream *fp) {
	cout << "closing file ... " << endl;
	fp->close();
}

using deleter = decltype(&close_file);

// unique_ptr with deleter
void deal_with_resource(unique_ptr<ifstream, deleter> fp) {
	if(fp) {
		string str;
		getline(*fp, str);
		cout << str << endl;
	} // here fp goes out of scope & deleter is run
}

int main() {

	string file_name{"file.txt"};
	ofstream(file_name) << "some text written to external file ...";

	// something like Java 'try with resources'
	unique_ptr<ifstream, deleter> fp { new ifstream(file_name), close_file };
	deal_with_resource(std::move(fp)); // move ptr to function & discard

	cout << "main() ends ..." << endl;
	return EXIT_SUCCESS;
}

