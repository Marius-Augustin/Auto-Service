#include "Autobus.h"

Autobus :: Autobus() : Vehicle() {
	setType("Autobus");
}

Autobus :: Autobus(int range, Date date, bool diesel, int seats) : Vehicle(range, date, diesel) {
	setType("Autobus");
	seatsNumber = seats;
}

Autobus :: Autobus(const Autobus & other) : Vehicle(other) {
	setType("Autobus");
	seatsNumber = other.seatsNumber;
}

Autobus :: ~Autobus() {
	delete [] type;
}

int Autobus :: getInsurance(bool discount) {
	int insurance = fabrication.getPastYears() * 200;
	if (dieselEngine) {
		insurance += 1000;
	}
	if (kilometrage > 200000) {
		insurance += 1000;
	} else if (kilometrage > 100000) {
		insurance += 500;
	}

	/* No need for float in this case. */ 
	if (discount) {
		return 0.90 * insurance;
	}
	return insurance;
}

void Autobus :: display() {
	cout << "Type: " << type << endl;
	Vehicle :: display();
	cout << "Seats: " << seatsNumber << endl;
}