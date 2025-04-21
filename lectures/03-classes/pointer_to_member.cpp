#include <iostream>
using namespace std;

struct bowl {
	int apples;
	int oranges;
};

using fruit_member_ptr = int bowl::*;

//int count_fruit(bowl* begin, bowl* end, int bowl::*fruit_ptr) {
int count_fruit(bowl* begin, bowl* end, fruit_member_ptr fruit_ptr) {
	int count{};
	for (bowl* iterator = begin; iterator != end; ++iterator) {
		count += iterator->*fruit_ptr;
	}
	return count;
}

void increment_fruit(bowl* b, fruit_member_ptr fruit_ptr) {
	++(b->*fruit_ptr);
}

int main() {
	bowl bowls[] = {
		{ 1, 2 },
		{ 3, 5 },
		{ 5, 1 }
	};
	int no_bowls = sizeof(bowls) / sizeof(bowls[0]);
	cout << "I have " << no_bowls << " bowls" << endl << endl;
	cout << "I have " << count_fruit(bowls, bowls + no_bowls, &bowl::apples)  << " apples" << endl;
	cout << "I have " << count_fruit(bowls, bowls + no_bowls, &bowl::oranges) << " oranges" << endl;
	cout << endl;

	increment_fruit(bowls, &bowl::apples);
	cout << "Now I have " << count_fruit(bowls, bowls + no_bowls, &bowl::apples) << " apples" << endl;
	increment_fruit(bowls + 2, &bowl::oranges);
	cout << "Now I have " << count_fruit(bowls, bowls + no_bowls, &bowl::oranges) << " oranges" << endl;

	return EXIT_SUCCESS;
}

