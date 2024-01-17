#include "Employee.h"

class Assistant: public Employee {
	float salaryCoefficient = 1;

public:
	Assistant();
	Assistant(const char *, const char *, Date, Date);
	Assistant(const Assistant &);
	
	void display();
	int getSalary();
};