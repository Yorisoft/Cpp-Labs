// Implementation file for the InvalidShift class
#include<string>
#include<iostream>
#include "InvalidShift.h"
using namespace std;

double InvalidShift::invalid_shift = 0;

// Constructor
InvalidShift::InvalidShift(double date) {
	invalid_shift = date;
}

// Accessors
double InvalidShift::getInvalidShift() {
	return invalid_shift;
}