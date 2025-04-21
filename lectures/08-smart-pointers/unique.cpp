#include <iostream>
#include <memory>
using namespace std;

class Task {

public:
	explicit Task() : id {++count} {
		cout << "Task(): " << id << endl;
	}
	~Task() {
		cout << "~Task(): " << id << endl;
	}
	friend ostream& operator<<(ostream& o, const Task& task) {
		return o << "Task: " << task.id << endl;
	}

private:
	static int count;
	int id;
};

int Task::count{};

void print_ptr(const unique_ptr<Task>& ptr) {
	// Check if unique pointer object is empty
	if(!ptr) cout << "ptr is empty" << endl;
	else cout << *ptr; // dereferences pointer to the managed object
}

int main() {

//  cannot create unique_ptr object by initializing through assignment
//  unique_ptr<Task> task_ptr_1 = new Task(); // Compile Error

//  Create a unique_ptr object through raw pointer
//	unique_ptr<Task> task_ptr_1(new Task()); // OK

//  Create a unique_ptr object through make_unique()
	unique_ptr<Task> task_ptr_1{ make_unique<Task>() };
	print_ptr(task_ptr_1);

	// Resetting the unique_ptr will delete the associated
	// raw pointer and make unique_ptr object empty
	cout << "Reset the task_ptr_1" << endl;
	task_ptr_1.reset();
	print_ptr(task_ptr_1);
	cout << endl;

	unique_ptr<Task> task_ptr_2{ make_unique<Task>() };
	print_ptr(task_ptr_2);

//	unique_ptr object is NOT copyable
//	task_ptr_1 = task_ptr_2; // compile error
//	unique_ptr<Task> task_ptr_3(task_ptr_2); // compile error
	{
		// Transfer the ownership
		cout << "move ptr_2" << endl;
		unique_ptr<Task> task_ptr_2_new(std::move(task_ptr_2));
		print_ptr(task_ptr_2);
		// ownership of task_ptr_2 is transferred to task_ptr_2_new
		print_ptr(task_ptr_2_new);
		//task_ptr_2_new goes out of scope and deletes the associated raw pointer
	}
	cout << endl;

	// Create a unique_ptr object through raw pointer
	unique_ptr<Task> task_ptr_3(new Task());
	print_ptr(task_ptr_3);

	// Release the ownership of object from raw pointer
	// The caller is responsible for deleting the object
	// returns a pointer to the managed object and releases the ownership
	Task* raw_ptr_3 = task_ptr_3.release();
	print_ptr(task_ptr_3);
	cout << *raw_ptr_3;
	delete raw_ptr_3;

	return EXIT_SUCCESS;
}

