#include "Employees/Director.h"
#include "Employees/Mechanic.h"
#include "Employees/Assistant.h"

#include "Vehicles/Standard.h"
#include "Vehicles/Autobus.h"
#include "Vehicles/Truck.h"

#include "Requests/Request.h"

#include <algorithm>
#include <vector>
#include <unistd.h> 
#include <cstdlib>

/* Flags used for Menu options. */
enum Options {
	OP, O1, O2, O3, O4, O5, O6
};

/* Employee Menu Operations. */
void createEmployeesMenu(vector <Employee *> &);
void displayEmployees(vector <Employee *>);
void addEmployee(vector <Employee *> &);
void removeEmployee(vector <Employee *> &);
void modifyEmployee(vector <Employee *> &);
void displaySalary(vector <Employee *>);

void displayError();
int findID(vector <Employee *>, int);
int verifyID(vector <Employee *>);
int getOption(int);

/* Requests Menu Operations. */
void createRequestsMenu(vector <Request *> &, vector <Employee *>);
void displayRequests(vector <Request *>);
void addRequest(vector <Request *> &, vector <Employee *>);
void updateRequestsTime(vector <Request *> &, vector <Employee *>);

/* Employee Menu Stats. */
void createStatsMenu(vector <Employee *> &);
void displayStatsMenu();
void highestScheduledEmployee(const vector <Employee *> &);
void highestEarningEmployees(vector <Employee *> &);
void mostRequestedEmployees(vector <Employee *> &);
void displayEmployeesTips(const vector <Employee *> &);