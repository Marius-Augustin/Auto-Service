#include "Vehicle.h"

class Truck: public Vehicle {
private:
	int weight;

public:
	Truck();
	Truck(int, Date, bool, int);
	Truck(const Truck &);

	void display();
	int getInsurance(bool);
	~Truck();
};

