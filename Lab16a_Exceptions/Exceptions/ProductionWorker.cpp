// Implementation file for the ProductionWorker class
#include<string>
#include<iostream>
#include "ProductionWorker.h"
#include "InvalidHireDate.h"
#include "InvalidShift.h"
#include "InvalidPayRate.h"
using namespace std;

// Default constructor
ProductionWorker::ProductionWorker() : Employee() {
	shift = 0; payRate = 0.0;
}
// Constructor
ProductionWorker::ProductionWorker(string aName, string aDate, int aShift, double aPayRate)
	: Employee(aName, aDate) {
	shift = aShift; payRate = aPayRate;
}

// Mutators
void ProductionWorker::setShift(double s) {
	if ((s == 1 || s == 2) || (int)s != s)
		throw InvalidShift(s);
	shift = s;
}
void ProductionWorker::setPayRate(double r) {
	if (r < 0)
		throw InvalidPayRate(r);
	payRate = r;
}
ProductionWorker* ProductionWorker::createNewProductionWorker() {
	ProductionWorker* nProdPtr = new ProductionWorker();
	try {
		cout << "Enter name of new employee: ";
		string name;
		getline(cin, name); nProdPtr->setEmployeeName(name);

		cout << "Enter hire date of new employee: ";
		string hDate;
		getline(cin, hDate); nProdPtr->setHireDate(hDate);

		cout << "Enter shift for new employee (1=day, 2=night): ";
		int shift;
		cin >> shift; nProdPtr->setShift(shift);

		cout << "Enter hourly pay rate for new employee: ";
		double pRate;
		cin >> pRate; nProdPtr->setPayRate(pRate);
	} catch (InvalidHireDate e) {
		cout << "Error: Invalid hire date [" << e.getInvalidDate() << "]: "
			<< "Hire date must be MM/DD/YYYY format." << endl;
	} catch (InvalidShift b) {
		cout << "Error: Invalid shift number: " << b.getInvalidShift()
			<< ". Shift number must be 1 or 2 " << endl;
	} catch (InvalidPayRate s) {
		cout << "Error: Invalid pay rate: " << s.getInvalidPayRate()
			<< ". Pay rate must be greater than 0 " << endl;
	} catch ( ... ) {
		cout << "Error: An error accoured while creating new prduction worker. "
			<< "Try again" << endl;
	}

	return nProdPtr;
}

// Accessors
double ProductionWorker::getShiftNumber() const {
	return shift;
}

string ProductionWorker::getShiftName() const {
	int i = (int)shift;
	string SHIFTNAMES[] = { "Day", "Night" };
	return SHIFTNAMES[i - 1];
}
double ProductionWorker::getPayRate() const {
	return payRate;
}
void ProductionWorker::displayInfo(ProductionWorker* e) {
	cout << "Name: " << e->getEmployeeName() << endl
		<< "Employee number: " << e->getEmployeeNumber() << endl
		<< "Hire date: " << e->getHireDate() << endl
		<< "Shift: " << e->getShiftName() << endl
		<< "Shift number: " << e->getShiftNumber() << endl
		<< "Pay rate: " << e->getPayRate() << endl;
}