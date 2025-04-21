#include<iostream>
using namespace std; 

// Placement new is a variation new operator in C++. Normal new operator does
// two things : (1) Allocates memory (2) Constructs an object in allocated
// memory.

// Placement new allows us to separate above two things. In placement new,
// we can pass a preallocated memory and construct an object in this memory.
  
int main() { 
    // buffer on stack 
    unsigned char buf[2 * sizeof(int)];
  
    // placement new in buf 
    int *pInt = new(buf) int{3};
    int *qInt = new(buf + sizeof(int)) int{5};

    cout << "Buff: " << (void*) buf << endl;
    cout << "pInt: " << pInt << endl;
    cout << "qInt: " << qInt << endl;
    cout << "------------------------------" << endl;
    cout << "*pInt: " << *pInt << endl;
    cout << "*qInt: " << *qInt << endl;

    return EXIT_SUCCESS;
} 

