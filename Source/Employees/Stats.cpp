#include "../Menu.h"

void displayStatsMenu() {
	system("clear");
	cout << "[1] - Display highest scheduled Employee." << endl;
	cout << "[2] - Display highest earning Employees." << endl;
	cout << "[3] - Display most Requested Employees." << endl;
	cout << "[4] - Display Employees Tips." << endl;
	cout << "[5] - Return to the Main Menu." << endl;
}

void createStatsMenu(vector <Employee *> & employees) {
	int option;

	if (!employees.size()) {
		cout << "There are no Employees." << endl;
		cout << "Operation finished." << endl; sleep(5); return; 
	}
	while(true) {
		displayStatsMenu();
		option = getOption(O5);
		system("clear");
		if (option == O1) {
			highestScheduledEmployee(employees);
		} else if (option == O2) {
			highestEarningEmployees(employees);
		} else if (option == O3) {
			mostRequestedEmployees(employees);
		} else if (option == O4) {
			displayEmployeesTips(employees);
		} else if (option == O5) {
			return;
		}
	}	
}

void highestScheduledEmployee(const vector <Employee *> & employees) {
	int position = 0;

	for (int i = 1; i < employees.size(); i++) {
		if (employees[position]->getTime() < employees[i]->getTime()) {
			position = i;
		}
	}

	employees[position]->displayName();
	cout << " - " << employees[position]->getTime() << " hours." << endl;
	cout << "Operation finished." << endl; sleep(5);
}

void highestEarningEmployees(vector <Employee *> & employees) {
	int length = (employees.size() < 3 ? employees.size() : 3);
	sort(employees.begin(), employees.end(), [](Employee * first, Employee * second) { 
    	return (first->getEarnings() < first->getEarnings() ? false : true);
	});

	for (int i = 0; i < length; i++) {
		employees[i]->displayName();
		cout << " - " << employees[i]->getEarnings() << " in earnings." << endl;
	}

	cout << "Operation finished." << endl; sleep(5);
}

void mostRequestedEmployees(vector <Employee *> & employees) {
	int length = (employees.size() < 3 ? employees.size() : 3);
	sort(employees.begin(), employees.end(), [](Employee * first, Employee * second) { 
    	return (first->getRequests() < first->getRequests() ? false : true);
	});
	
	for (int i = 0; i < length; i++) {
		employees[i]->displayName();
		cout << " - " << employees[i]->getRequests() << " in requests." << endl;
	}

	cout << "Operation finished." << endl; sleep(5);
}

void displayEmployeesTips(const vector <Employee *> & employees) {
	for (int i = 0; i < employees.size(); i++) {
		employees[i]->displayName();
		cout << " - " << employees[i]->getEarnings() / 100 << " in tips." << endl;
	}

	cout << "Operation finished." << endl; sleep(5);
}