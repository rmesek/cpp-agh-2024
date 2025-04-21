#include<iostream>
#include<cstring>
using namespace std;

//	Template overloading:

template<typename T> T max_t(T a, T b) { // #1
	cout << "O#1:\t";
	return (a > b) ? a : b;
}

template<typename T> T* max_t(T* a, T* b) { // #2
	cout << "O#2:\t";
	return ((*a) > (*b)) ? a : b;
}

template<typename T> T max_t(T* data, int n) { // #3
	cout << "O#3:\t";
	T _max = data[0];
	for(int i = 1; i < n; ++i)
		if(data[i] >_max) _max = data[i];
	return _max;
}

//	Template specialization:

template<> char* max_t(char *a, char *b) { // #4, specialization of #2
	cout << "S#4:\t";
	return (strcmp(a, b) > 0) ? a : b;
}

template<> const char* max_t(const char *a, const char *b) { //	#5, specialization of #2
	cout << "S#5:\t";
	return (strcmp(a, b) > 0) ? a : b;
}

//	The above specializations are complete (they specify all the template arguments),
//	so the template parameter list in these templates is empty. Specialization, as
//	opposed to overloading, has to specialize already defined template. That's
//	why the following is illegal (the parameters are of different types):

//	template<> const char* max_t(char *a, const char *b) {
//		return (strcmp(a, b) > 0) ? a : b;
//	}

//	Next to templates, we can define non-template functions with the same name.
//	The overloading algorithm chooses the latter.

int max_t(int a, int b) { // #6
	cout << "O#6:\t";
	return (a > b) ? a : b;
}

int main() {

	cout << max_t(0, 1) << endl;			//	non-template #6, int max_t(int, int)
	cout << max_t(0, 1.5) << endl;			//	non-template #6, int max_t(int, int) (with double->int)
	cout << max_t<double>(0, 1.5) << endl;	//	template #1, T = double (explicit instantiation)
	cout << max_t<int>(0, 1) << endl;		//	template #1, T = int
	cout << max_t(0.0, 1.0) << endl;		//	template #1, T = double

	int i{2}, j{3};
	cout << *max_t(&i, &j) << endl;	    	//	template #2, T = int
	//	also matches #1 with T = int*, but #2 is
	//	"more specialized" (with smaller set of potential parameters).
	//	A template function F is more specialized than template function G if
	//	every set of arguments that matches F matches G, but not the opposite.

	double x[]{1, 2, 4, 0, 3};
	cout << max_t(x, 5) << endl;            //	template #3
	cout << endl;

	char p1[]{"ania"};
	char p2[]{"asia"};
	cout << max_t(p1, p2) << endl;			//	template #4
	cout << max_t("asia", "ania") << endl;	//	template #5
//	cout << max_t("asia", p1) << endl;		//	error: parameter types differ

	return EXIT_SUCCESS;
}

