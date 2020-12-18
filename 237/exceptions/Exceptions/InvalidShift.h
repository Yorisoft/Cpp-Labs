// Specification file for the InvalidHireDate class
#ifndef INVALID_SHIFT
#define INVALID_SHIFT
#include<string>
#include<iostream>
using namespace std;

class InvalidShift
{
private:
	static double invalid_shift;

public:
	// Constructor
	InvalidShift(double date);

	// Accessors
	static double getInvalidShift();
};
#endif