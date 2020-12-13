// Implementation file for the InvalidHireDate class
#include<string>
#include<iostream>
#include "InvalidHireDate.h"
using namespace std;

string InvalidHireDate::invalidDate = " "; // Sequential employee number

// Constructor
InvalidHireDate::InvalidHireDate(string date) {
	invalidDate = date;
}

// Accessors
string InvalidHireDate::getInvalidDate() {
	return invalidDate;
}