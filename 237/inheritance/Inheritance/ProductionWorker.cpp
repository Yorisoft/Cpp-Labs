// Implementation file for the ProductionWorker class

#include<string>
#include "ProductionWorker.h"
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
void ProductionWorker::setShift(int s) {
	shift = s;
}
void ProductionWorker::setPayRate(double r) {
	payRate = r;
}
ProductionWorker* ProductionWorker::createNewProductionWorker() {
	ProductionWorker* nProdPtr = new ProductionWorker();

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

	return nProdPtr;
}

// Accessors
int ProductionWorker::getShiftNumber() const {
	return shift;
}

string ProductionWorker::getShiftName() const {	
	string SHIFTNAMES[] = { "Day", "Night" };
	return SHIFTNAMES[shift-1];
}
double ProductionWorker::getPayRate() const {
	return payRate;
}
void ProductionWorker::displayInfo(ProductionWorker *e) {
	cout << "Name: " << e->getEmployeeName() << endl
	<< "Employee number: " << e->getEmployeeNumber() << endl
	<< "Hire date: " << e->getHireDate() << endl
	<< "Shift: " << e->getShiftName() << endl
	<< "Shift number: " << e->getShiftNumber() << endl
	<< "Pay rate: " << e->getPayRate() << endl;
}