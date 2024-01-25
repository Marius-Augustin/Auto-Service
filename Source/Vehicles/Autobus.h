#include "Vehicle.h"

class Autobus: public Vehicle {
private:
	int seatsNumber;

public:
	Autobus();
	Autobus(int, Date, bool, int);
	Autobus(const Autobus &);

	void display();
	int getInsurance(bool);
	~Autobus();
};

