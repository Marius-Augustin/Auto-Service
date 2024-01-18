#include "Employee.h"

class Director: public Employee {
	float salaryCoefficient = 2;

public:
	Director();
	Director(const char *, const char *, Date, Date);
	Director(const Director &);
	
	void display();
	int getSalary();
};