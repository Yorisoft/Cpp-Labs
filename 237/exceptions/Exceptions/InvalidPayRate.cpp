// Implementation file for the InvalidPayRate class
#include<string>
#include<iostream>
#include "InvalidPayRate.h"
using namespace std;

double InvalidPayRate::InvalidPR = 0;

// Constructor
InvalidPayRate::InvalidPayRate(double p) {
	InvalidPR = p;
}

// Accessors
double InvalidPayRate::getInvalidPayRate() {
	return InvalidPR;
}