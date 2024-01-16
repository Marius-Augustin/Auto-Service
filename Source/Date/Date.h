#pragma once

#include <iostream>
#include <ctime>

using namespace std;

class Date {
	int day;
	int month;
	int year;

public:
	Date();
	Date(int, int, int);
	int getPastYears();
	bool isValid();
	bool isMajor();
	void display();
};