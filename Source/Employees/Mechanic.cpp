#include "Mechanic.h"

Mechanic :: Mechanic() : Employee() {
	setTitle("Mechanic");
}

Mechanic :: Mechanic(const char * myName, const char * mySurname, Date birth, Date start) : Employee(myName, mySurname, birth, start) {
	setTitle("Mechanic");
}

Mechanic :: Mechanic(const Mechanic & other) : Employee(other){
	setTitle("Mechanic");
}
	
void Mechanic :: display() {
	cout << "Title: " << title << endl;
	Employee::display();
}

int Mechanic :: getSalary() {
	return startDate.getPastYears() * salaryCoefficient * 1000;
}