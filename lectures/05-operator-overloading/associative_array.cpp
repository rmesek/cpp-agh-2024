#include <iostream>
#include <algorithm>
using namespace std;

class Word {

public:
	explicit
	Word(string s = ""s) : str{std::move(s)}, count{} {}

	Word operator++() {
		count++;
		return *this;
	}

	Word operator++(int) {
		Word temp = *this;
		++(*this);
		return temp;
	}

	bool operator==(const string& s) const {
		return this->str == s;	//	string class == operator
	}

	ostream& print(ostream& os) const {
		return os << str << ": " << count << endl;
	}

private:
	string str;
	int count;
};

ostream& operator<<(ostream& os, const Word &word) {
	return word.print(os);
}

class Map {

public:
	Word& operator[](const string& str) {
		for (int i = 0; i < n; i++) {
			if (word_array[i] == str) return word_array[i];
		}
		word_array[n] = Word(str);
		return word_array[n++];
	}

	ostream& print(ostream& out) const {
		for (int i = 0; i < n; i++) 
			word_array[i].print(out);
		return out;
	}

private:
	static constexpr int size{10000};
	int n{};
	Word word_array[size];
};

ostream &operator<<(ostream &os, const Map &map) {
	return map.print(os);
}

int main () {
	Map associative_array;
	string str;
	while(cin >> str) {
		transform(str.begin(), str.end(), str.begin(), ::tolower);
		++associative_array[str];
	}
	cout << associative_array;

	return EXIT_SUCCESS;
}

