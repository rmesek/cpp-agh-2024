#include <iostream>
#include <memory>
#include <thread>

using namespace std;

// shared_ptr<Type> is implicitly convertible to weak_ptr<void>
void observe(const weak_ptr<int>& wp, thread &observer) {
	//Start observer thread
	observer = thread([wp] {
		while(true) {
			//Try acquiring a shared_ptr from weak_ptr
			if(shared_ptr<int> p = wp.lock()) {
				//Success
				cout << "Observing: " << (*p)++ << endl;
				this_thread::sleep_for(chrono::seconds(1));
			} else {
				//The managed object is destroyed.
				cout << "Stop" << endl;
				break;
			}
		}
	});
}

int main() {

	thread observer;
	{
		auto sp = make_shared<int>();
		//Create a weak_ptr<int> from sp for observing
		observe(sp, observer);
		//Wait few seconds
		this_thread::sleep_for(chrono::seconds(5));

		// shared_ptr is destroyed and the managed object is deleted
		// when block ends
	}

	//Wait for the observer thread to end
	observer.join();

	return EXIT_SUCCESS;
}

