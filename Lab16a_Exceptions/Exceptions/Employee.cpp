// Implementation file for the Employee class

#include <string>
#include<iostream>
#include "Employee.h"
#include "InvalidHireDate.h"
using namespace std;

int Employee::lastEmployeeNumberIssued = 0; // Sequential employee number

	// Default constructor
Employee::Employee()
{
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = "";
	hireDate = "";
}

// Constructor
Employee::Employee(string aName, string aDate)
{
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = aName;
	hireDate = aDate;
}

// Mutators
void Employee::setEmployeeName(string n)
{
	employeeName = n;
}

void Employee::setHireDate(string date)
{
	// check digits are in the right place
	for (int y = 0; y < date.length(); y++) {
		if (!isdigit(date[y]))
			throw InvalidHireDate(date);
		(y == 1 || y == 4) ? y++ : y; // Skip over char's
	}
	// check chars are in the right place
	if (!(date.at(2) == '/' && date.at(5) == '/'))
		throw InvalidHireDate(date);

	hireDate = date;
}

// Accessors
string Employee::getEmployeeName() const
{
	return employeeName;
}

int Employee::getEmployeeNumber() const
{
	return employeeNumber;
}

string Employee::getHireDate() const
{
	return hireDate;
}

int Employee::getLastEmployeeNumberIssued()
{
	return lastEmployeeNumberIssued;
}