// Specification file for the InvalidHireDate class
#ifndef INVALID_HIRE_DATE
#define INVALID_HIRE_DATE
#include<string>
#include<iostream>
using namespace std;

class InvalidHireDate
{
private:
	static string invalidDate;

public:
	// Constructor
	InvalidHireDate(string date);

	// Accessors
	static string getInvalidDate();
};
#endif