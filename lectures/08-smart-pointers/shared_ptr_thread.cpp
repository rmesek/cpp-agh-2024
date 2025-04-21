#include <iostream>
#include <memory>
#include <atomic>
#include <thread>
using namespace std;

int main() {

	auto sp = make_shared<atomic_int>(10);

	// Reader: A weak_ptr is created and captured
	// Has to start first to acquire the sp pointer before writer
	// captures it
	thread reader([wp = weak_ptr<atomic_int>{sp}] {
		while(true) {
			if(auto p = wp.lock()) { // Acquire a shared_ptr through lock()
				cout << *p << " " << p.use_count() << endl; // shared_ptr acquired (count 1 or 2)
			} else {
				break; // shared_ptr could not be acquired (count 0)
			}
			this_thread::sleep_for(chrono::milliseconds (1000));
		}
		cout << "reader ended\n";
	});

	// Writer
	// The shared_ptr is moved and captured so the ref count stays 1
	// If the shared_ptr is copied instead of moved, this program will never
	// end because the reader would never exit (try that!).

	thread writer([mp = std::move(sp)] { //shared_ptr moved, ref count: 1
		for(int i = 0; i < 5; i++) {
			(*mp)++; //change managed object
			this_thread::sleep_for(chrono::seconds (1));
		}
		cout << "writer ended\n";
	}); // mp destroyed here so reader will exit

	writer.join(); // wait for writer
	reader.join(); // wait for reader

	return EXIT_SUCCESS;
}

