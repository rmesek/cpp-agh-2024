#ifndef CPP_ALL_STAFF_H
#define CPP_ALL_STAFF_H

struct Date {
	int day;
	int month;
	int year;
};

struct Employee {
	char lastname[20];
	char firstname[20];
	char address[100];
	double wages;
	Date birthdate;
	Date employment_date;
};

int read_staff_data (Employee*);
void print_employees(Employee*, int);

#endif //CPP_ALL_STAFF_H
