#include "../Menu.h"

void displayError() {
	cout << "Your input does not respect the application guideline!" << endl;
	sleep(2.5); system("clear");
}

void displayErrorName() {
	cout << "Your name cannot be NULL or have more than 30 characters!" << endl;
	sleep(2.5); system("clear");

}

void displayErrorDate() {
	cout << "Your date cannot be placed in the future! The employee must be major!" << endl;
	sleep(2.5); system("clear");
}

/* Find the Position + 1 in the Employee array for an input ID. */ 
int findID(vector <Employee *> employees, int ID) {
	for (int i = 0; i < employees.size(); i++) {
		if (ID == employees[i]->getID()) {
			return i + 1;
		}
	}
	return false;
}

/* Force the User to input an ID found in the Employee array. */
int verifyID(vector <Employee *> employees) {
	int error = true, ID, position;

	while (error) {
		system("clear");
		cout << "Insert ID: "; cin >> ID;
		position = findID(employees, ID);
		if (position) {
			error = false;
		} else {
			displayError();
		}
	}
	return position;
}

void displayEmployeesMenu() {
	system("clear");
	cout << "[1] - Display all available employees." << endl;
	cout << "[2] - Add employee record." << endl;
	cout << "[3] - Delete employee record." << endl;
	cout << "[4] - Modify employee record." << endl;
	cout << "[5] - Display employee salary" << endl;
	cout << "[6] - Return to the Main Menu." << endl;
}

void createEmployeesMenu(vector <Employee *> & employees) {
	int option = 0;

	while(true) {
		displayEmployeesMenu();
		option = getOption(O6);

		if (option == O1) {
			displayEmployees(employees);
		} else if (option == O2) {
			addEmployee(employees);
		} else if (option == O3) {
			removeEmployee(employees);
		} else if (option == O4) {
			modifyEmployee(employees);
		} else if (option == O5) {
			displaySalary(employees);
		} else if (option == O6) {
			return;
		} 
	}	
}

void displayEmployees(vector <Employee *> employees) {
	system("clear");
	for (int i = 0; i < employees.size(); i++) {
		employees[i]->display();
		cout << endl;
	}
	sleep(5);
}

int getOption(int optionLimit) {
	int option;
	
	while(true) {
		cout << "Choose your option " << "[1 - ";
		cout << optionLimit << "]: ";
		cin >> option;
		if (option >= 1 and option <= optionLimit) {
			return option;
		} else {
			displayError();
		}
	}
}

void addEmployee(vector <Employee *> & employees) {
	char name[30], surname[30];
	int day, month, year, error = true;
	Date birth, start;

	system("clear");
	cout << "Director [1] | Mechanic [2] | Assistent [3]" << endl;
	int option = getOption(O3);

	while(error) {
		system("clear");
		error = false;

		cout << "Name: "; cin >> name;
		cout << "Surname: "; cin >> surname;
		cout << "Birthdate(Day / Month / Year): "; cin >> day >> month >> year;
		birth = Date(day, month, year);
		cout << "Startdate(Day / Month / Year): "; cin >> day >> month >> year;
		start = Date(day, month, year);

		if (!name or !surname or strlen(name) > 30 or strlen(surname) > 30) {
			error = true;
			displayErrorName();	
		}
		if (!birth.isMajor() or !start.isValid()) {
			error = true;
			displayErrorDate();
		}
	}

	if (option == O1) {
			employees.push_back(new Director(name, surname, birth, start));
	} else if (option == O2) {
			employees.push_back(new Mechanic(name, surname, birth, start));
	} else if (option == O3) {
			employees.push_back(new Assistant(name, surname, birth, start));
	}
}

void removeEmployee(vector <Employee *> & employees) {
	int position = verifyID(employees);
	employees.erase(employees.begin() + position - 1);
}

void modifyEmployee(vector <Employee *> & employees) {
	char name[30], surname[30];
	int day, month, year;
	int ID, position, error = true;
	Date birth, start;

	position = verifyID(employees);

	while(error) {
		system("clear");
		error = false;

		cout << "Name: "; cin >> name;
		cout << "Surname: "; cin >> surname;
		cout << "Birthdate(Day / Month / Year): "; cin >> day >> month >> year;
		birth = Date(day, month, year);
		cout << "Startdate(Day / Month / Year): "; cin >> day >> month >> year;
		start = Date(day, month, year);

		if (!name or !surname or strlen(name) > 30 or strlen(surname) > 30) {
			error = true;
			displayErrorName(); 
		}
		if (!birth.isMajor() or !start.isValid()) {
			error = true;
			displayErrorDate();
		}
	}
	employees[position - 1]->modify(name, surname, birth, start);
}

void displaySalary(vector <Employee *> employees) {
	int ID, position, error = true;
	position = verifyID(employees);

	cout << "Salary: " << employees[position - 1]->getSalary() << endl;
	sleep(2.5);
}