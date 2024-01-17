#include "Employee.h"

class Mechanic: public Employee {
	float salaryCoefficient = 1.5;

public:
	Mechanic();
	Mechanic(const char *, const char *, Date, Date);
	Mechanic(const Mechanic &);
	
	void display();
	int getSalary();
};