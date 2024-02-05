#include "Menu.h"

using namespace std;

void displayMainMenu() {
	system("clear");
	cout << "[1] - Operations - Employees." << endl;
	cout << "[2] - Operations - Requests." << endl;
	cout << "[3] - Display Statistics." << endl;
	cout << "[4] - Exit the Application." << endl;
}

int main() {
	vector <Employee *> employees;
	vector <Request *> requests;

	while(true) {
		displayMainMenu();
		int option = getOption(O4);

		if (option == O1) {
			createEmployeesMenu(employees);
		} else if (option == O2) {
			createRequestsMenu(requests, employees);
		} else if (option == O3) {
			createStatsMenu(employees);	
		} else if (option == O4) {
			return 0;
		} else {
			displayError();
		}
	}

	return 0;
}