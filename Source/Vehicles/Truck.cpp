#include "Truck.h"

Truck :: Truck() : Vehicle() {
	setType("Truck");
	weight = 0;
}

Truck :: Truck(int range, Date date, bool diesel, int myWeight) : Vehicle(range, date, diesel) {
	setType("Truck");
	weight = myWeight;
}

Truck :: Truck(const Truck & other) : Vehicle(other) {
	setType("Truck");
	weight = other.weight;
}

Truck :: ~Truck() {
	delete [] type;
}

int Truck :: getInsurance(bool discount) {
	int insurance = fabrication.getPastYears() * 300;
	
	if (kilometrage > 800000) {
		insurance += 700;
	}
	/* No need for float in this case. */ 
	if (discount) {
		return 0.85 * insurance;
	}
	return insurance;
}

void Truck :: display() {
	cout << "Type: " << type << endl;
	Vehicle :: display();
	cout << "Weight: " << weight << endl; 
}