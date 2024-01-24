#pragma once
#include "../Date/Date.h"
#include <string.h>

class Vehicle {
protected:
	static int ID;
	int currentID;
	char * type = NULL;

	int kilometrage;
	Date fabrication;
	bool dieselEngine;

	void setType(const char *);

public:
	Vehicle();
	Vehicle(int, Date, bool);
	Vehicle(const Vehicle &);
	Vehicle & operator=(const Vehicle &);
	
	virtual void display();
	virtual int getInsurance(bool) = 0;
	virtual ~Vehicle();
};
