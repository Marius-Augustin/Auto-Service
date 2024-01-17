#include "Assistant.h"

Assistant :: Assistant() : Employee() {
	setTitle("Assistant");
}

Assistant :: Assistant(const char * myName, const char * mySurname, Date birth, Date start) : Employee(myName, mySurname, birth, start) {
	setTitle("Assistant");
}

Assistant :: Assistant(const Assistant & other) : Employee(other){
	setTitle("Assistant");
}
	
void Assistant :: display() {
	cout << "Title: " << title << endl;
	Employee::display();
}

int Assistant :: getSalary() {
	return startDate.getPastYears() * salaryCoefficient * 1000;
}