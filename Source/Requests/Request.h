#include "../Employees/Employee.h"
#include "../Vehicles/Vehicle.h"

class Request {
	Employee * assigned = NULL;
	Vehicle * myVehicle = NULL;
	int finishTime = 0;

public:
	Request(Employee *, Vehicle *, int);
	Request(const Request &);
	Request & operator=(const Request &);
	~Request();

	void updateEarnings();
	int getFinishTime();
	void reduceFinishTime(int &);
	void display();
};