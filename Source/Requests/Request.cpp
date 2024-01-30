#include "Request.h"

Request :: Request(Employee * employee, Vehicle * vehicle, int time) {
	assigned = employee;
	myVehicle = vehicle;
	finishTime = time;
} 

void Request :: display() {
	cout << "Assigned employee ID: ";
	cout << assigned->getID() << endl;
	myVehicle->display();
	cout << "Finish Time: " << finishTime << endl;	
}

int Request :: getFinishTime() {
	return finishTime;
}

void Request :: reduceFinishTime(int & hours) {
	if (finishTime - hours > 0) {
		finishTime += -hours;
	} else {
		finishTime = 0;
	}
}

void Request :: updateEarnings() {
	assigned->addEarnings(myVehicle->getInsurance(true));	
}

Request :: ~Request() {
	delete myVehicle;
}