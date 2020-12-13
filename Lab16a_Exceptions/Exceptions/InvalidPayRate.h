// Specification file for the InvalidShift class
#ifndef INVALID_PAY_RATE
#define INVALID_PAY_RATE
#include<string>
#include<iostream>
using namespace std;

class InvalidPayRate
{
private:
	static double InvalidPR;

public:
	// Contructor
	InvalidPayRate(double date);

	// Accessors
	static double getInvalidPayRate();
};
#endif