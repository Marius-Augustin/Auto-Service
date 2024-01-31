#include "../Menu.h"

void displayRequestsMenu() {
	system("clear");
	cout << "[1] - View Requests Queue." << endl;
	cout << "[2] - Insert a new Request." << endl;
	cout << "[3] - Advance Time." << endl;
	cout << "[4] - Return to Main Menu." << endl;
}

bool getConfirmation() {
	char confirmation;
	while(true) {
		cout << "(Y / N): ";
		cin >> confirmation;
		if (confirmation == 'Y') {
			return true;
		} else if (confirmation == 'N') {
			return false;
		} else {
			cout << "Input Error! Choose only with (Y / N)." << endl;
			displayError();
		}
	}
}

Vehicle * readVehicle() {
	int range, day, month, year;
	int seats, option, weight;
	bool engine, manual;
	char confirmation;

	cout << "Insert the information of your vehicle." << endl;

	cout << "Standard [1] | Autobus [2] | Truck [3]" << endl;
	option = getOption(O3);

	cout << "Kilometrage: "; cin >> range;
	cout << "Fabrication Date (Day / Month / Year): ";
	cin >> day >> month >> year;
	Date fabrication = Date(day, month, year);

	cout << "Diesel Engine?" << endl;
	if (getConfirmation()) {
		engine = true;
	} else {
		engine = false;
	}

	if (option == O1) {
		cout << "Manual Transmission?" << endl;
		if (getConfirmation()) {
			engine = true;
		} else  {
			engine = false;
		}
		return new Standard(range, fabrication, engine, manual);
	} else if (option == O2) {
		cout << "Seats: "; cin >> seats;
		return new Autobus(range, fabrication, engine, seats);
	} else if (option == O3) {
		cout << "Weight: "; cin >> weight;
		return new Truck(range, fabrication, engine, weight);
	}
}

int getBestTime(vector <Employee *> employees) {
	int bestPosition = 0;	
	int bestTime = employees[bestPosition]->getTime();
		
	for (int i = 0; i < employees.size(); i++) {
		if (employees[i]->getTime() < bestTime) {
			bestTime = employees[i]->getTime();
			bestPosition = i;
		}
	}

	return bestPosition + 1;
}

int defaultRequest(vector <Employee *> employees) {
	int position, time;
	char confirmation;

	cout << "Proceeding with the best available option." << endl;
	position = getBestTime(employees);
	
	time = employees[position - 1]->getTime();
	if (time == 0) {
		cout << "Our employee will start working on your vehicle immediately" << endl;
	} else {
		cout << "The waiting time for employee is " << time;
		cout << " hours. Proceed anyway?" << endl;
		if (getConfirmation()) {
			return position;
		} else {
			return false; 
		}
	}
	return position;
}

int specialRequest(vector <Employee *> employees) {
	int position = 0, time, ID;
	char confirmation;

	system("clear"); cout << "Request an employee?" << endl;
	if (getConfirmation()) {
		position = verifyID(employees);
		time = employees[position - 1]->getTime();
		employees[position - 1]->addRequests();
		if (time == 0) {
			cout << "Our employee will start working on your vehicle immediately." << endl;
			return position;
		} else {
			cout << "The waiting time for the requested employee is " << time;
			cout << " hours. Proceed anyway?" << endl;
			if (getConfirmation()) {
				return position;
			} else {
				cout << "Proceed with the best available option?" << endl;
				if (getConfirmation()) {
					return defaultRequest(employees);
				} else {
					return false;
				}
			}
		}
	} else {
		return defaultRequest(employees);
	}
}

void addRequest(vector <Request *> & requests, vector <Employee *> employees) {
	if (employees.size() == 0) {
		cout << "No available employee at the moment." << endl; 
		sleep(2.5); return;
	}

	int position, estimation, time;
	Vehicle * vehicle = readVehicle();

	if (position = specialRequest(employees)) {
		time = employees[position - 1]->getTime();
		estimation = rand() % 5 + 1;

		employees[position - 1]->setEmployTime(time + estimation);
		requests.push_back(new Request(employees[position - 1], vehicle, time + estimation));
		cout << "Successful Request." << endl; sleep(2.5);
	} else {
		cout << "Rejected Request." << endl;
		sleep(2.5); return;
	}
}

void displayRequests(vector <Request *> requests) {
	for (int i = 0; i < requests.size(); i++) {
		requests[i]->display();
		cout << endl;
	}
	cout << "Operation finished."; sleep(10);
}

void updateRequestsTime(vector <Request *> & requests, vector <Employee *> employees) {
	int hours = 0;
	cout << "Hours to advance the time: "; cin >> hours;

	for (int i = requests.size() - 1; i >= 0; i += -1) { 
		requests[i]->reduceFinishTime(hours);
		if (requests[i]->getFinishTime() == 0) {
			requests[i]->updateEarnings();
			requests.erase(requests.begin() + i);
		}
	}

	for (int i = 0; i < employees.size(); i += 1) {
		employees[i]->setEmployTime(employees[i]->getTime() - hours);
	}
}

void createRequestsMenu(vector <Request *> & requests, vector <Employee *> employees) {
	int option = 0;

	while(true) {
		displayRequestsMenu();
		option = getOption(O4);
		system("clear");
		if (option == O1) {
			displayRequests(requests);
		} else if (option == O2) {
			addRequest(requests, employees);
		} else if (option == O3) {
			updateRequestsTime(requests, employees);
		} else if (option == O4) {
			return;
		}
	}
}