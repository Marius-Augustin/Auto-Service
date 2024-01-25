#include "Vehicle.h"

class Standard: public Vehicle {
private:
	bool manualTransmission;

public:
	Standard();
	Standard(int, Date, bool, bool);
	Standard(const Standard &);

	void display();
	int getInsurance(bool);
	~Standard();
};