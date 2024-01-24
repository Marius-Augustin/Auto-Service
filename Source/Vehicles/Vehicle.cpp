#include "Vehicle.h"

int Vehicle :: ID = 0;

Vehicle :: Vehicle() {
	Vehicle :: ID += 1;
	currentID = Vehicle :: ID;
	kilometrage = 0;
}

Vehicle :: Vehicle(int range, Date date, bool diesel) {
	Vehicle :: ID += 1;
	currentID = Vehicle :: ID;
	kilometrage = range;
	fabrication = date;
	dieselEngine = diesel;
}

Vehicle :: Vehicle(const Vehicle & other) {
	Vehicle :: ID += 1;
	currentID = Vehicle :: ID;
	kilometrage = other.kilometrage;
	fabrication = other.fabrication;
	dieselEngine = other.dieselEngine;
}

Vehicle & Vehicle :: operator=(const Vehicle & other) {
	
	if (this != &other) {
		kilometrage = other.kilometrage;
		fabrication = other.fabrication;
		dieselEngine = other.dieselEngine;
	}

	return *this;
}	

Vehicle :: ~Vehicle() {
	delete [] type;
}

void Vehicle :: setType(const char * myType) {
	delete [] type;
	type = new char[strlen(myType) + 1];
	strcpy(type, myType);
}

void Vehicle :: display() {
	cout << "ID: " << currentID << endl;
	cout << "Kilometrage: " << kilometrage << endl;
	cout << "Fabrication: "; fabrication.display();
	cout << "Diesel Engine: ";
	if (dieselEngine) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}