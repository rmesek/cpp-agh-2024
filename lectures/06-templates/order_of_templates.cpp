#include<iostream>
using namespace std;

template<class T>	//	(a) a base template 
void f1(T) { cout << "f1 #a" << endl; }

template<class T>	//	(b) a second base template, overloads (a) 
void f1(T*) { cout << "f1 #b" << endl; }

template<>			//	(c) explicit specialization of (b) 
void f1<>(int*) { cout << "f1 #c" << endl; }

//	The Dimov / Abrahams Example 

template<class T>	//	(a) same old base template as before 
void f2(T) { cout << "f2 #a" << endl; }

template<>			//	(c) explicit specialization, this time of (a)
void f2<>(int*) { cout << "f2 #c" << endl; }

template<class T>	//	(b) a second base template, overloads (a) 
void f2(T*) { cout << "f2 #b" << endl; }

int main() {
	int *p{}; 
	f1(p);			//	calls (c)
	f2(p);			//	calls (b)! overload resolution ignores 
					//	specializations and operates on the base 
					//	function templates only

	return EXIT_SUCCESS;
}

