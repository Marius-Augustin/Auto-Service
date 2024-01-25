#include "Standard.h"

Standard :: Standard() : Vehicle() {
	setType("Standard");
}

Standard :: Standard(int range, Date date, bool diesel, bool manual) : Vehicle(range, date, diesel) {
	setType("Standard");
	manualTransmission = manual;	
}

Standard :: Standard(const Standard & other) : Vehicle(other) {
	setType("Standard");
	manualTransmission = other.manualTransmission;
}

Standard :: ~Standard() {
	delete [] type;
}

int Standard :: getInsurance(bool discount) {
	int insurance = fabrication.getPastYears() * 100;
	if (dieselEngine) {
		insurance += 500;
	}
	if (kilometrage > 200000) {
		insurance += 500;
	}

	/* No need for float in this case. */ 
	if (discount) {
		return 0.95 * insurance;
	}
	return insurance;
}

void Standard :: display() {
	cout << "Type: " << type << endl;
	Vehicle :: display();
	cout << "Manual Transmission: ";
	if (manualTransmission) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}