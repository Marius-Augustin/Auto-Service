#pragma once

#include "../Date/Date.h"
#include <string.h>

class Employee {
protected:
	static int ID;
	int currentID;
	char * title = NULL;
	char * name = NULL;
	char * surname = NULL;
	Date birthDate;
	Date startDate;
	
	int employTime = 0;
	int totalEarnings = 0;
 	int customerRequests = 0;
	
	void setTitle(const char *);
	void setName(const char *);
	void setSurname(const char *);

public:
	Employee();
	Employee(const char *, const char *, Date, Date);
	Employee(const Employee &);
	Employee & operator=(const Employee &);
	void modify(const char *, const char *, Date, Date);

	int getID();
	int getTime();
	int getRequests();
	int getEarnings();
	
	void addEarnings(int);
	void addRequests();
	void setEmployTime(int);
	void displayName();

	virtual void display();
	virtual int getSalary() = 0;
	virtual ~Employee();
};