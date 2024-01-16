#include "Date.h"

using namespace std;

Date :: Date() {
	day = 0;
	month = 0;
	year = 0;
}

Date :: Date(int myDay, int myMonth, int myYear) {
	day = myDay;
	month = myMonth;
	year = myYear;
}

/* Return the number of years that have passed from the actual moment. */

int Date :: getPastYears() {
	time_t now = time(0);
	tm * current = localtime(&now);

	if (month == current->tm_mon + 1) {
		if (day <= current->tm_mday)
			return current->tm_year + 1900 - year;
		else {
			return current->tm_year + 1900 - year - 1;
		}
	} else if (month > current->tm_mon + 1) {
		return current->tm_year + 1900 - year - 1;
	} else {
		return current->tm_year + 1900 - year;
	}
}

bool Date :: isValid() {
	if (getPastYears() >= 0) {
		return true;
	}
	return false;
}

bool Date :: isMajor() {
	if (getPastYears() >= 18) {
		return true;
	}
	return false;
}

void Date :: display() {
	cout << day << ".";
	cout << month << ".";
	cout << year << endl;  
}