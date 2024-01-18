#include "Director.h"

Director :: Director() : Employee() {
	setTitle("Director");
}

Director :: Director(const char * myName, const char * mySurname, Date birth, Date start) : Employee(myName, mySurname, birth, start) {
	setTitle("Director");
}

Director :: Director(const Director & other) : Employee(other){
	setTitle("Director");
}
	
void Director :: display() {
	cout << "Title: " << title << endl;
	Employee::display();
}

int Director :: getSalary() {
	return startDate.getPastYears() * salaryCoefficient * 1000;
}