#include "Employee.h"

int Employee :: ID = 0;

Employee :: Employee() {
	Employee::ID += 1;
	currentID = Employee::ID;
	setName("Empty!");
	setSurname("Empty!");
}

Employee :: Employee(const char * myName, const char * mySurname, Date birth, Date start) {
	Employee::ID += 1;
	currentID = Employee::ID;
	setName(myName);
	setSurname(mySurname);
	birthDate = birth;
	startDate = start;
}

Employee :: Employee(const Employee & other) {
	Employee::ID += 1;
	currentID = Employee::ID;
	setName(other.name);
	setSurname(other.surname);
	birthDate = other.birthDate;
	startDate = other.startDate;
	employTime = other.employTime;
}

Employee & Employee :: operator=(const Employee & other) {
	if (this != &other) {
		setName(other.name);
		setSurname(other.surname);
		birthDate = other.birthDate;
		startDate = other.startDate;
	}

	return (*this);
}

void Employee :: modify(const char * myName, const char * mySurname, Date birth, Date start) {
	setName(myName);
	setSurname(mySurname);
	birthDate = birth;
	startDate = start;
}

int Employee :: getID() {
	return currentID;
}

int Employee :: getTime() {
	return employTime;
}

int Employee :: getRequests() {
	return customerRequests;
}

int Employee :: getEarnings() {
	return totalEarnings;
}

void Employee :: addEarnings(int earnings) {
	totalEarnings += earnings;
}

void Employee :: addRequests() {
	customerRequests += 1;
}

void Employee :: setEmployTime(int time) {
	if (time >= 0) {
		employTime = time;
	} else {
		employTime = 0;
	}
}

void Employee :: display() {
	cout << "ID: " << currentID << endl;
	cout << "Name: " << name << endl;
	cout << "Surname: " << surname << endl;
	cout << "Birthdate: "; birthDate.display();
	cout << "Startdate: "; startDate.display();
}

void Employee :: displayName() {
	cout << name << " " << surname;
}

void Employee :: setName(const char * myName) {
	delete [] name;
	name = new char[strlen(myName) + 1];
	strcpy(name, myName);
}

void Employee :: setSurname(const char * mySurname) {
	delete [] surname;
	surname = new char[strlen(mySurname) + 1];
	strcpy(surname, mySurname);
}

void Employee :: setTitle(const char * myTitle) {
	delete [] title;
	title = new char[strlen(myTitle) + 1];
	strcpy(title, myTitle);
}

Employee :: ~Employee() {
	delete [] name;
	delete [] surname;
}